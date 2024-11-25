#include <weavess/builder.h>
#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
string absolute_path = "/data/kabir/similarity-search/dataset/";

void NSG(std::string base_path, std::string query_path, std::string ground_path, std::string graph_file, unsigned K = 100) {
    unsigned L, Iter, S, R, L_refine, R_refine, C;

    weavess::Parameters parameters;
    L = 120, Iter = 12, S = 25, R = 300, L_refine = 150, R_refine = 30, C = 400;
    parameters.set<unsigned>("K", K);
    parameters.set<unsigned>("L", L);
    parameters.set<unsigned>("ITER", Iter);
    parameters.set<unsigned>("S", S);
    parameters.set<unsigned>("R", R);

    parameters.set<unsigned>("L_refine", L_refine);
    parameters.set<unsigned>("R_refine", R_refine);
    parameters.set<unsigned>("C_refine", C);
    auto *builder = new weavess::IndexBuilder(1);
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> init(weavess::INIT_RANDOM)
            -> refine(weavess::REFINE_NN_DESCENT, false);
    std::cout << "Init cost: " << builder->GetBuildTime().count() << std::endl;
    builder -> refine(weavess::REFINE_NSG, false)
            -> save_graph(weavess::TYPE::INDEX_NSG, &graph_file[0]);
    std::cout << "Build cost: " << builder->GetBuildTime().count() << std::endl;
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> load_graph(weavess::TYPE::INDEX_NSG, &graph_file[0])
            -> search(weavess::TYPE::SEARCH_ENTRY_CENTROID, weavess::TYPE::ROUTER_GREEDY, weavess::TYPE::L_SEARCH_ASCEND,K);
}

int testGenericNSG(string dataset, int K, int cs) {
    freopen(("../../nsg_logs/"+dataset+to_string(cs)+".txt").c_str(),"a+",stdout);
    cout<<(dataset+" test")<<endl;
    std::string base_path = dataset+"/base.fvecs";
    std::string query_path = dataset+"/query.fvecs";
    std::string ground_path = dataset+"/groundtruth.ivecs";
    std::string graph = "../../nsg_graphs/"+dataset+to_string(cs)+".graph";
    NSG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K);

    return 0;  
}

int main(int argc, char* argv[]) {
	for (int i=1;i<argc;i+=3) {
        string dataset=argv[i];
        testGenericNSG(dataset, atoi(argv[i+1]), atoi(argv[i+2]));   
    }
    return 0;
}