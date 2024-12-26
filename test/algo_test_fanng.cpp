#include <weavess/builder.h>
#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
string absolute_path = "/data/kabir/similarity-search/dataset/";

void FANNG(std::string base_path, std::string query_path, std::string ground_path, std::string graph_file, unsigned L, unsigned R, unsigned K = 100) {

    weavess::Parameters parameters;
    parameters.set<unsigned>("K", K);
    parameters.set<unsigned>("L", L);
    parameters.set<unsigned>("R", R);
    auto *builder = new weavess::IndexBuilder(1);
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
                -> init(weavess::TYPE::INIT_FANNG);
    std::cout << "Init cost: " << builder->GetBuildTime().count() << std::endl;
    builder -> refine(weavess::TYPE::REFINE_FANNG, false)
                -> save_graph(weavess::TYPE::INDEX_FANNG, &graph_file[0]);
    std::cout << "Build cost: " << builder->GetBuildTime().count() << std::endl;
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
                -> load_graph(weavess::TYPE::INDEX_FANNG, &graph_file[0])
                -> search(weavess::TYPE::SEARCH_ENTRY_RAND, weavess::TYPE::ROUTER_BACKTRACK, weavess::TYPE::L_SEARCH_ASCEND,K);

}

int testGenericFANNG(string dataset, int K, int cs) {
    freopen(("../../nsg_logs/"+dataset+to_string(cs)+".txt").c_str(),"a+",stdout);
    cout<<(dataset+" test")<<endl;
    std::string base_path = dataset+"/base.fvecs";
    std::string query_path = dataset+"/query.fvecs";
    std::string ground_path = dataset+"/groundtruth.ivecs";
    std::string graph = "../../nsg_graphs/"+dataset+to_string(cs)+".graph";
    unsigned L, R;
    if (cs==0) {
        L=100;
        R=25;
    }
    if (cs==1) {
        L=100;
        R=50;
    }
    if (cs==2) {
        L=100;
        R=100;
    }
    if (cs==3) {
        L=150;
        R=25;
    }
    if (cs==4) {
        L=150;
        R=50;
    }
    if (cs==5) {
        L=150;
        R=100;
    }
    if (cs==6) {
        L=200;
        R=25;
    }
    if (cs==7) {
        L=200;
        R=50;
    }
    if (cs==8) {
        L=200;
        R=100;
    }
    FANNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, L, R, K);

    return 0;  
}

int main(int argc, char* argv[]) {
	for (int i=1;i<argc;i+=3) {
        string dataset=argv[i];
        testGenericFANNG(dataset, atoi(argv[i+1]), atoi(argv[i+2]));   
    }
    return 0;
}