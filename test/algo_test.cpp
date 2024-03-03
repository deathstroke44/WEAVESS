//
// Created by MurphySL on 2020/12/7.
//
#include <weavess/builder.h>
#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
string absolute_path = "/data/kabir/similarity-search/dataset/";

void KDRG(std::string base_path, std::string query_path, std::string ground_path) {
    std::string graph = "basin.graph";
    weavess::Parameters parameters;
    parameters.set<unsigned>("S", 50);
    parameters.set<unsigned>("R_refine", 10);

    auto* builder= new weavess::IndexBuilder(1);
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> init(weavess::INIT_KNNG, true)
            -> refine(weavess::REFINE_KDRG, true)
            -> save_graph(weavess::INDEX_KGRAPH, &graph[0]);

    auto *builder2 = new weavess::IndexBuilder(1);
    builder2 -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> load_graph(weavess::INDEX_KGRAPH, &graph[0])
            -> search(weavess::SEARCH_ENTRY_RAND, weavess::ROUTER_GREEDY, weavess::TYPE::L_SEARCH_ASCEND);

    std::cout << "Time cost: " << builder->GetBuildTime().count() << std::endl;
}

void EFANNA(std::string base_path, std::string query_path, std::string ground_path) {
    std::string graph = "efanna.graph";
    weavess::Parameters parameters;
    parameters.set<unsigned>("nTrees", 8);
    parameters.set<unsigned>("mLevel", 8);
    parameters.set<unsigned>("S", 100);

    parameters.set<unsigned>("K", 200);
    parameters.set<unsigned>("L", 200);
    parameters.set<unsigned>("ITER", 12);
    parameters.set<unsigned>("S", 10);
    parameters.set<unsigned>("R", 100);

    auto *builder = new weavess::IndexBuilder(1);
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> init(weavess::INIT_KDT, true)
            -> refine(weavess::REFINE_EFANNA, true)
            -> save_graph(weavess::INDEX_EFANNA, &graph[0]);

    auto *builder2 = new weavess::IndexBuilder(1);
    builder2 -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> load_graph(weavess::INDEX_EFANNA, &graph[0])
            -> search(weavess::SEARCH_ENTRY_KDT, weavess::ROUTER_GREEDY, weavess::TYPE::L_SEARCH_ASCEND);

    std::cout << "Time cost: " << builder->GetBuildTime().count() << std::endl;
}

void NSW(std::string base_path, std::string query_path, std::string ground_path) {
    weavess::Parameters parameters;
    parameters.set<unsigned>("NN", 10);          // K
    parameters.set<unsigned>("ef_construction", 50);        //L
    parameters.set<unsigned>("n_threads_", 1);

    auto *builder = new weavess::IndexBuilder(1);
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> init(weavess::INIT_NSW)
            -> search(weavess::SEARCH_ENTRY_NONE, weavess::ROUTER_NSW, weavess::TYPE::L_SEARCH_ASCEND);

    std::cout << "Time cost: " << builder->GetBuildTime().count() << std::endl;
}

void PANNG(std::string base_path, std::string query_path, std::string ground_path) {
    std::string graph_file = R"(panng.graph)";

    weavess::Parameters parameters;
    parameters.set<unsigned>("NN", 10);          // K
    parameters.set<unsigned>("ef_construction", 50);        //L
    parameters.set<unsigned>("n_threads_", 1);
    //parameters.set<unsigned>("batchSizeForCreation", 200);

    auto *builder = new weavess::IndexBuilder(1);
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> init(weavess::INIT_ANNG)
            -> refine(weavess::REFINE_PANNG, false)
            -> save_graph(weavess::INDEX_PANNG, &graph_file[0]);

    auto *builder2 = new weavess::IndexBuilder(1);
    builder2 -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> load_graph(weavess::INDEX_PANNG, &graph_file[0])
            -> search(weavess::SEARCH_ENTRY_VPT, weavess::ROUTER_NGT, weavess::TYPE::L_SEARCH_ASCEND);

//    std::cout << "Time cost: " << builder->GetBuildTime().count() << std::endl;
}

void ONNG(std::string base_path, std::string query_path, std::string ground_path) {
    std::string graph_file = R"(onng.graph)";

    weavess::Parameters parameters;
    parameters.set<unsigned>("NN", 50);          // K
    parameters.set<unsigned>("ef_construction", 100);        //L
    parameters.set<unsigned>("n_threads_", 1);

    parameters.set<unsigned>("numOfOutgoingEdges", 20);
    parameters.set<unsigned>("numOfIncomingEdges", 50);
    parameters.set<unsigned>("numOfQueries", 200);
    parameters.set<unsigned>("numOfResultantObjects", 20);

    auto *builder = new weavess::IndexBuilder(1);
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> init(weavess::INIT_ANNG, true)
            -> refine(weavess::REFINE_ONNG, true)
            -> refine(weavess::REFINE_PANNG, true)
            -> load_graph(weavess::INDEX_ONNG, &graph_file[0]);

    auto *builder2 = new weavess::IndexBuilder(1);
    builder2 -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
             -> save_graph(weavess::INDEX_ONNG, &graph_file[0])
            -> search(weavess::SEARCH_ENTRY_VPT, weavess::ROUTER_NGT, weavess::TYPE::L_SEARCH_SET_RECALL);

    std::cout << "Time cost: " << builder->GetBuildTime().count() << std::endl;
}

void SPTAG_KDT(std::string base_path, std::string query_path, std::string ground_path) {
    std::string graph = "sptag_kdt.graph";
    weavess::Parameters parameters;
    parameters.set<unsigned>("KDTNumber", 1);
    parameters.set<unsigned>("TPTNumber", 32);
    parameters.set<unsigned>("TPTLeafSize", 500);
    parameters.set<unsigned>("NeighborhoodSize", 32);
    parameters.set<unsigned>("GraphNeighborhoodScale", 2);
    parameters.set<unsigned>("CEF", 500);
    parameters.set<unsigned>("numOfThreads", 10);

    auto *builder = new weavess::IndexBuilder(1);
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> init(weavess::INIT_SPTAG_KDT)
            -> refine(weavess::REFINE_SPTAG_KDT, false)
            -> save_graph(weavess::INDEX_SPTAG_KDT, &graph[0])
//     builder        -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> load_graph(weavess::INDEX_SPTAG_KDT, &graph[0])
            -> search(weavess::SEARCH_ENTRY_NONE, weavess::ROUTER_SPTAG_KDT, weavess::TYPE::L_SEARCH_ASCEND);
    std::cout << "Time cost: " << builder->GetBuildTime().count() << std::endl;
}

void SPTAG_BKT(std::string base_path, std::string query_path, std::string ground_path) {
    std::string graph = "sptag_bkt.graph";

    weavess::Parameters parameters;

    parameters.set<unsigned>("BKTNumber", 1);
    parameters.set<unsigned>("BKTKMeansK", 4);
    parameters.set<unsigned>("TPTNumber", 4);
    parameters.set<unsigned>("TPTLeafSize", 1000);
    parameters.set<unsigned>("NeighborhoodSize", 32);
    parameters.set<unsigned>("GraphNeighborhoodScale", 2);
    parameters.set<unsigned>("CEF", 500);
    parameters.set<unsigned>("numOfThreads", 10);

    auto *builder = new weavess::IndexBuilder(1);
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> init(weavess::INIT_SPTAG_BKT)
            -> refine(weavess::REFINE_SPTAG_BKT, false)
            -> save_graph(weavess::INDEX_SPTAG_BKT, &graph[0]);

    auto *builder2 = new weavess::IndexBuilder(1);
    builder2 -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> load_graph(weavess::INDEX_SPTAG_BKT, &graph[0])
            -> search(weavess::SEARCH_ENTRY_NONE, weavess::ROUTER_SPTAG_BKT, weavess::TYPE::L_SEARCH_ASCEND);

    //std::cout << "Time cost: " << builder->GetBuildTime().count() << std::endl;
}

void HCNNG(std::string base_path, std::string query_path, std::string ground_path, unsigned K = 20, std::string graph = "hcnng.graph", int minsize_cl=100, int num_cl=20, int nTrees=10, int mLevel=4) {
    cout<<"Graph name: "<<graph<<endl;
    weavess::Parameters parameters;
    parameters.set<unsigned>("minsize_cl", minsize_cl);
    parameters.set<unsigned>("num_cl", num_cl);

    parameters.set<unsigned>("nTrees", nTrees);
    parameters.set<unsigned>("mLevel", mLevel);
    parameters.set<unsigned>("K", K);

    auto *builder = new weavess::IndexBuilder(1);
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> init(weavess::INIT_HCNNG)
            -> save_graph(weavess::INDEX_HCNNG, &graph[0]);

    auto *builder2 = new weavess::IndexBuilder(1);
    builder2 -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> load_graph(weavess::INDEX_HCNNG, &graph[0])
            -> search(weavess::SEARCH_ENTRY_KDT, weavess::ROUTER_GUIDE, weavess::TYPE::L_SEARCH_ASCEND, K);

    //std::cout << "Time cost: " << builder->GetBuildTime().count() << std::endl;
}


int testGenericHCNNG(string dataset, int K) {
    cout<<(dataset+" test")<<endl;
    freopen(("../../new_efanna_logs/"+dataset+".txt").c_str(),"a+",stdout);
    std::string base_path = dataset+"/base.fvecs";
    std::string query_path = dataset+"/query.fvecs";
    std::string ground_path = dataset+"/groundtruth.ivecs";
    std::string graph = "../../graphs/"+dataset+".graph";

    HCNNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, K, graph);
    HCNNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, K, graph, 50, 20);
    HCNNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, K, graph, 100, 10);

    return 0;  
}

int testGenericHCNNG2(string dataset, int K, int cs) {
    cout<<(dataset+" test")<<endl;
    freopen(("../../new_efanna_logs/"+dataset+to_string(cs)+".txt").c_str(),"a+",stdout);
    std::string base_path = dataset+"/base.fvecs";
    std::string query_path = dataset+"/query.fvecs";
    std::string ground_path = dataset+"/groundtruth.ivecs";
    std::string graph = "../../graphs/"+dataset+".graph";
    // int minsize_cl=100, int num_cl=20, int nTrees=10, int mLevel=4
    if(cs==0) HCNNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, K, graph);
    if(cs==1) HCNNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, K, graph, 50, 20);
    if(cs==2) HCNNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, K, graph, 100, 10);
    if(cs==3) HCNNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, K, graph, 100, 5);
    if(cs==4) HCNNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, K, graph, 50, 5);
    if(cs==5) HCNNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, K, graph, 50, 10);
    if(cs==6) HCNNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, K, graph, 20, 10);
    if(cs==7) HCNNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, K, graph, 10, 10);
    if(cs==8) HCNNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, K, graph, 100, 10, 5);
    if(cs==9) HCNNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, K, graph, 100, 10, 10, 2);
    if(cs==10) HCNNG(absolute_path + base_path, absolute_path + query_path, absolute_path + ground_path, K, graph, 100, 10, 10, 8);

    return 0;  
}

int main(int argc, char* argv[]) {
	
    for (int i=1;i<argc;i+=3) {
        string dataset=argv[i];
        testGenericHCNNG2(dataset, atoi(argv[i+1]), atoi(argv[i+2]));
        // if (strcmp(argv[i],"sift1m") == 0) {
        //         cout<<"Sift1m test"<<endl;
        //         testSift1m();
        // }
        // else if (strcmp(argv[i],"gist") == 0) {
        //         cout<<"gist test"<<endl;
        //         testGist1m();
        // }
        // else if (strcmp(argv[i],"glove") == 0) {
        //         cout<<"glove test"<<endl;
        //         testGlove();
        // }
        // else if (strcmp(argv[i],"imagenet") == 0) {
        //         cout<<"imagenet test"<<endl;
        //         testimageNet();
        // }
        // else if (strcmp(argv[i],"notre") == 0) {
        //         cout<<"notre test"<<endl;
        //         testnotre();
        // }
        // else if (strcmp(argv[i],"ukbench") == 0) {
        //         cout<<"ukbench test"<<endl;
        //         testukbench();
        // }
        // else if (strcmp(argv[i],"crawl") == 0) {
        //         cout<<"crawl test"<<endl;
        //         testCrawl();
        // }
        // else if (strcmp(argv[i],"audio") == 0) {
        //         cout<<"audio test"<<endl;
        //         testAudio();
        // }
        // else if (strcmp(argv[i],"cifer") == 0) {
        //         cout<<"cifer test"<<endl;
        //         testCifar();
        // }
        // else if (strcmp(argv[i],"enron") == 0) {
        //         cout<<"enron test"<<endl;
        //         testEnron();
        // }
        // else if (strcmp(argv[i],"millionSong") == 0) {
        //         cout<<"millionSong test"<<endl;
        //         testmillionSong();
        // }
        // else if (strcmp(argv[i],"MNIST") == 0) {
        //         cout<<"MNIST test"<<endl;
        //         testMnist();
        // }
        // else if (strcmp(argv[i],"nuswide") == 0) {
        //         cout<<"nuswide test"<<endl;
        //         testNuswide();
        // }
        // else if (strcmp(argv[i],"sun") == 0) {
        //         cout<<"sun test"<<endl;
        //         testSun();
        // }
        // else if (strcmp(argv[i],"deep") == 0) {
        //         cout<<"deep test"<<endl;
        //         testDeep();
        // }
        // else if (strcmp(argv[i],"trevi") == 0) {
        //         cout<<"trevi test"<<endl;
        //         testTrevi();
        // }
        // else if (strcmp(argv[i],"uqv") == 0) {
        //         cout<<"uqv test"<<endl;
        //         testUqv();
        // }
        // else if (strcmp(argv[i],"nytimes") == 0) {
        //         cout<<"nytimes test"<<endl;
        //         testNyTimes();
        // }
        // else if (strcmp(argv[i],"lastfm") == 0) {
        //         cout<<"lastfm test"<<endl;
        //         testLastFm();
        // }
        
    }

    return 0;
}
