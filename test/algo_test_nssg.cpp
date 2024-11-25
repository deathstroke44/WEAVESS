#include <weavess/builder.h>
#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
string absolute_path = "/data/kabir/similarity-search/dataset/";

void NSSG(std::string base_path, std::string query_path, std::string ground_path, std::string graph_file, unsigned K = 100) {
    unsigned L, Iter, S, R, L_refine, R_refine;

    weavess::Parameters parameters;
    L = 100, Iter = 12, S = 10, R = 100, L_refine = 50, R_refine = 60;
    parameters.set<unsigned>("K", K);
    parameters.set<unsigned>("L", L);
    parameters.set<unsigned>("ITER", Iter);
    parameters.set<unsigned>("S", S);
    parameters.set<unsigned>("R", R);

    parameters.set<unsigned>("L_refine", L_refine);
    parameters.set<unsigned>("R_refine", R_refine);
    parameters.set<float>("A", 60);
    parameters.set<unsigned>("n_try", 10);
    auto *builder = new weavess::IndexBuilder(1);
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> init(weavess::INIT_RANDOM)
            -> refine(weavess::REFINE_NN_DESCENT, false);
    std::cout << "Init cost: " << builder->GetBuildTime().count() << std::endl;
    builder -> refine(weavess::REFINE_SSG, false)
            -> save_graph(weavess::TYPE::INDEX_SSG, &graph_file[0]);
    std::cout << "Build cost: " << builder->GetBuildTime().count() << std::endl;
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
                -> load_graph(weavess::TYPE::INDEX_SSG, &graph_file[0])
                -> search(weavess::SEARCH_ENTRY_SUB_CENTROID, weavess::ROUTER_GREEDY, weavess::TYPE::L_SEARCH_ASCEND,K);
}

int testGenericNSSG(string dataset, int K, int cs) {
    freopen(("../../nssg_logs/"+dataset+to_string(cs)+".txt").c_str(),"a+",stdout);
    cout<<(dataset+" test")<<endl;
    std::string base_path = dataset+"/base.fvecs";
    std::string query_path = dataset+"/query.fvecs";
    std::string ground_path = dataset+"/groundtruth.ivecs";
    std::string graph = "../../nssg_graphs/"+dataset+to_string(cs)+".graph";
    NSSG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, graph, K);

    return 0;  
}

int main(int argc, char* argv[]) {
	for (int i=1;i<argc;i+=3) {
        string dataset=argv[i];
        testGenericNSSG(dataset, atoi(argv[i+1]), atoi(argv[i+2]));   
    }
    return 0;
}