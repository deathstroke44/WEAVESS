//
// Created by MurphySL on 2020/12/7.
//
#include <weavess/builder.h>
#include <iostream>
using namespace std;
string absolute_path = "/data/kabir/similarity-search/dataset/";




void ONNG(std::string base_path, std::string query_path, std::string ground_path, std::string graph, unsigned K = 20, unsigned L = 50, int S=10, int R=100, int nTrees=8, int mLevel=8) {
    std::string graph_file = graph;

    weavess::Parameters parameters;

    parameters.set<unsigned>("nTrees", nTrees);
    parameters.set<unsigned>("mLevel", mLevel);

    parameters.set<unsigned>("K", K);
    parameters.set<unsigned>("L", L);
    parameters.set<unsigned>("ITER", 12);
    parameters.set<unsigned>("S", S);
    parameters.set<unsigned>("R", R);

    auto *builder = new weavess::IndexBuilder(1);
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> init(weavess::INIT_KDT, true)
            -> refine(weavess::REFINE_EFANNA, true)
            -> save_graph(weavess::INDEX_EFANNA, &graph[0]);

    auto *builder2 = new weavess::IndexBuilder(1);
    builder2 -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> load_graph(weavess::INDEX_EFANNA, &graph[0])
            -> search(weavess::SEARCH_ENTRY_KDT, weavess::ROUTER_GREEDY, weavess::TYPE::L_SEARCH_ASCEND, K);

    std::cout << "Time cost: " << builder->GetBuildTime().count() << std::endl;
}


int testGenericDPG(string dataset, int K, int cs) {
    int S=10, R=100, nTrees=8, mLevel=8;
    freopen(("../../original_efanna_logs/"+dataset+to_string(cs)+".txt").c_str(),"a+",stdout);
    cout<<(dataset+" test")<<endl;
    std::string base_path = dataset+"/base.fvecs";
    std::string query_path = dataset+"/query.fvecs";
    std::string ground_path = dataset+"/groundtruth.ivecs";
    std::string graph = "../../dpg_graphs/"+dataset+to_string(cs)+".graph";
    if(cs==0) {
		ONNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K + 30);
	}
    if(cs==1) {
		ONNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K + 30, 10);
	}
    if(cs==2) {
		ONNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K + 30, 20, 50);
	}
	if(cs==3) {
		ONNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K);
	}
	if(cs==4) {
		ONNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K, S, R, nTrees, mLevel);
	}
	if(cs==5) {
		ONNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K, S, R, nTrees*2, mLevel);
	}
	if(cs==6) {
		ONNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K, S, R, nTrees, mLevel*2);
	}
	if(cs==7) {
		ONNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K, S+10, R, nTrees, mLevel);
	}
	if(cs==8) {
		ONNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K, S, R+50, nTrees, mLevel);
	}
	if(cs==9) {
		ONNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K, S+10, R, nTrees, mLevel);
	}
	if(cs==10) {
		ONNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K, S+20, R, nTrees, mLevel);
	}
	if(cs==11) {
		ONNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K, S+10, R+50, nTrees, mLevel);
	}
	if(cs==12) {
		ONNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K, K, S+20, R+100, nTrees, mLevel);
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