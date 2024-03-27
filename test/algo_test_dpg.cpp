//
// Created by MurphySL on 2020/12/7.
//
#include <weavess/builder.h>
#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
string absolute_path = "/data/kabir/similarity-search/dataset/";

void DPG(std::string base_path, std::string query_path, std::string ground_path, std::string graph_file, unsigned K = 100, unsigned L = 100, unsigned Iter = 12, unsigned S = 20, unsigned R = 100) {
	weavess::Parameters parameters;
	parameters.set<unsigned>("K", K);
    parameters.set<unsigned>("L", L);
    parameters.set<unsigned>("ITER", Iter);
    parameters.set<unsigned>("S", S);
    parameters.set<unsigned>("R", R);
    parameters.set<unsigned>("n_threads", 1);
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

int testGenericDPG(string dataset, int K, int cs) {
    freopen(("../../new_dpg_logs/"+dataset+to_string(cs)+".txt").c_str(),"a+",stdout);
    cout<<(dataset+" test")<<endl;
    std::string base_path = dataset+"/base.fvecs";
    std::string query_path = dataset+"/query.fvecs";
    std::string ground_path = dataset+"/groundtruth.ivecs";
    std::string graph = "../../dpg_graphs/"+dataset+to_string(cs)+".graph";
    if(cs==0) {
		DPG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K + 30);
	}
    if(cs==1) {
		DPG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K + 30, 12, 10);
	}
    if(cs==2) {
		DPG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K + 30, 12, 20, 50);
	}
	if(cs==3) {
		DPG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K);
	}
    if(cs==4) {
		DPG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K, 12, 20, 25);
	}
    if(cs==5) {
		DPG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K, 12, 20, 12);
	}
    if(cs==6) {
		DPG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K, 12, 10, 12);
	}
    if(cs==7) {
		DPG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K, 12, 5, 12);
	}
    if(cs==8) {
		DPG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K + 30, 12, 20, 25);
	}
    if(cs==9) {
		DPG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K + 30, 12, 20, 12);
	}
    if(cs==10) {
		DPG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K + 30, 12, 10, 12);
	}
    if(cs==11) {
		DPG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K + 30, 12, 5, 12);
	}

    return 0;  
}

int main(int argc, char* argv[]) {
	
    for (int i=1;i<argc;i+=3) {
        string dataset=argv[i];
        testGenericDPG(dataset, atoi(argv[i+1]), atoi(argv[i+2]));
        
    }

    return 0;
}
