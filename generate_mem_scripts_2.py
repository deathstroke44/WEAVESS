datasets=['imageNet','sift','ukbench','uqv','deep']
ks=[20,100,20,100,20]
models=['algo_test_nssg','algo_test_nsg']
testCnts=[0,0]
testCntsStart=[0,0]
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