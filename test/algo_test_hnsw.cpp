//
// Created by MurphySL on 2020/12/7.
//
#include <weavess/builder.h>
#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
string absolute_path = "/data/kabir/similarity-search/dataset/";

void HNSW(std::string base_path, std::string query_path, std::string ground_path, std::string graph_file, unsigned max_m, unsigned max_m0, unsigned ef_construction, unsigned K) {
	weavess::Parameters parameters;
	parameters.set<unsigned>("max_m", max_m);
    parameters.set<unsigned>("max_m0", max_m0);
    parameters.set<unsigned>("ef_construction", ef_construction);
    parameters.set<int>("mult", -1);
    auto *builder = new weavess::IndexBuilder(1);
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
			-> init(weavess::INIT_RANDOM)
			-> refine(weavess::REFINE_NN_DESCENT, false);
	std::cout << "Init cost: " << builder->GetBuildTime().count() << std::endl;
	builder -> refine(weavess::REFINE_DPG, false)
			-> save_graph(weavess::TYPE::INDEX_DPG,  &graph_file[0]);
	std::cout << "Build cost: " << builder->GetBuildTime().count() << std::endl;

	builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
                -> load_graph(weavess::TYPE::INDEX_DPG,  &graph_file[0])
                -> search(weavess::TYPE::SEARCH_ENTRY_RAND, weavess::TYPE::ROUTER_GREEDY, weavess::TYPE::L_SEARCH_ASCEND, K);

    
}

int testGenericHNSW(string dataset, int K, int cs) {
    freopen(("../../hnsw_logs/"+dataset+to_string(cs)+".txt").c_str(),"a+",stdout);
    cout<<(dataset+" test")<<endl;
    std::string base_path = dataset+"/base.fvecs";
    std::string query_path = dataset+"/query.fvecs";
    std::string ground_path = dataset+"/groundtruth.ivecs";
    std::string graph = "../../hnsw_graphs/"+dataset+to_string(cs)+".graph";
    if(cs==1) {
		HNSW(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, 50, 60, 400, K);
	}
    if(cs==2) {
		HNSW(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, 10, 40, 200, K);
	}
    if(cs==3) {
		HNSW(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, 10, 40, 300, K);
	}
    if(cs==4) {
		HNSW(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, 20, 40, 300, K);
	}
    if(cs==5) {
		HNSW(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, 10, 50, 300, K);
	}

    return 0;  
}

int main(int argc, char* argv[]) {
	
    for (int i=1;i<argc;i+=3) {
        string dataset=argv[i];
        testGenericHNSW(dataset, atoi(argv[i+1]), atoi(argv[i+2]));
        
    }

    return 0;
}
