datasets=['imageNet','sift','ukbench','uqv','deep']
ks=[20,100,20,100,20]
models=['algo_test','algo_test_dpg','algo_test_efanna','algo_test_hnsw','algo_test_vamana']
testCnts=[13,25,12,5,4]
testCntsStart=[0,0,0,1,1]
tmp='/usr/bin/time -v ./[model] [dataset] [k] [case]  &> ../../memlogs/[dataset]-[case]-[model].log &  '

for i in range(0,len(models)):
    for k in range(0,len(datasets)):
        for j in range(testCntsStart[i],testCnts[i]+1):
            cmd=tmp+''
            cmd=cmd.replace('[model]',models[i])
            cmd=cmd.replace('[dataset]',datasets[k])
            cmd=cmd.replace('[case]',str(j))
            cmd=cmd.replace('[k]',str(ks[k]))
            print(cmd,end='')
print('echo 1')