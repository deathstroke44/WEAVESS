//
// Created by MurphySL on 2020/12/7.
//
#include <weavess/builder.h>
#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
string absolute_path = "/data/kabir/similarity-search/dataset/";

void VAMANA(std::string base_path, std::string query_path, std::string ground_path, std::string graph_file, unsigned R, unsigned L, unsigned K) {
	weavess::Parameters parameters;
	parameters.set<unsigned>("L", R);
    parameters.set<unsigned>("L_refine", L);
    parameters.set<unsigned>("R_refine", R);
    auto *builder = new weavess::IndexBuilder(1);
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> init(weavess::INIT_RAND);
    std::cout << "Init cost: " << builder->GetBuildTime().count() << std::endl;
    builder -> refine(weavess::REFINE_VAMANA, false)
            -> refine(weavess::REFINE_VAMANA, false)
            -> save_graph(weavess::TYPE::INDEX_VAMANA, &graph_file[0]);
    std::cout << "Build cost: " << builder->GetBuildTime().count() << std::endl;

	builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
                -> load_graph(weavess::TYPE::INDEX_VAMANA, &graph_file[0])
                -> search(weavess::TYPE::SEARCH_ENTRY_CENTROID, weavess::TYPE::ROUTER_GREEDY, weavess::TYPE::L_SEARCH_ASCEND,K);
    builder -> peak_memory_footprint();
}

int testGenericVAMANA(string dataset, int K, int cs) {
    freopen(("../../vamana_logs/"+dataset+to_string(cs)+".txt").c_str(),"a+",stdout);
    cout<<(dataset+" test")<<endl;
    std::string base_path = dataset+"/base.fvecs";
    std::string query_path = dataset+"/query.fvecs";
    std::string ground_path = dataset+"/groundtruth.ivecs";
    std::string graph = "../../vamana_graphs/"+dataset+to_string(cs)+".graph";
    if(cs==1) {
		VAMANA(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, 8, 16, K);
	}
    if(cs==2) {
		VAMANA(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, 16, 32, K);
	}
    if(cs==3) {
		VAMANA(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, 32, 64, K);
	}
    if(cs==4) {
		VAMANA(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, 16, 8, K);
	}

    return 0;  
}

int main(int argc, char* argv[]) {
	
    for (int i=1;i<argc;i+=3) {
        string dataset=argv[i];
        testGenericVAMANA(dataset, atoi(argv[i+1]), atoi(argv[i+2]));
        
    }

    return 0;
}
