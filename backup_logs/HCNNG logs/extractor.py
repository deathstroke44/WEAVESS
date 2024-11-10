import re
import csv
data = []
filename = "experiment_results.csv"

def getRecall(matches):
    ret = ['','']
    if len(matches)==0:
        return ret
    for i in range(0,2):
        if len(matches) >= i+1:
            x = matches[i].split(': ')[1].split(' ')[0]
            ret[i]=float(x)
    return ret

def getMap(matches):
    ret = ['','']
    if len(matches)==0:
        return ret
    for i in range(0,2):
        if len(matches) >= i+1:
            x = matches[i].split('MAP: ')[1]
            ret[i]=float(x)
    return ret

def getTrainingTime(str):
    if (len(str)==0):
        return ''
    x = str[0].split('Training time: ')[1].split(' s')[0]
    return float(x)

def getEncodingTime(str):
    if (len(str)==0):
        return ''
    x = str[0].split('Encoding time: ')[1].split(' s')[0]
    return float(x)

def getQueryTime(str):
    if (len(str)==0):
        return ''
    x = str[0].split('Querying time: ')[1].split(' s')[0]
    return float(x)
    
    

def parseSingleRecord(result):
    dict = {}
    rc = re.findall("NN recall:.*", result)
    mp = re.findall("NN map@:.*", result)
    k = re.findall("SEARCH_L :.*", result)
    st = re.findall("search time:.*", result)
    
    return (k,st,rc,mp)
    

def extractFile(fileName):
    with open(fileName, 'r') as file:
        st = file.read()
        r=parseSingleRecord(st)
        print(r)
        data.append([fileName, '', ''])
        for i in range(0,len(r[0])):
            data.append([r[0][i].split(': ')[1],
                         r[1][i].split(': ')[1], 
                         r[2][i].split(': ')[1], 
                         r[3][i].split(': ')[1]
                         ])
        
extractFile('audio.txt')
extractFile('cifar.txt')
extractFile('crawl.txt')
extractFile('deep.txt')
extractFile('enron.txt')
extractFile('gist1m.txt')
extractFile('glove.txt')
extractFile('imageNet.txt')
extractFile('lastfm.txt')
            
        


# # audio cifar enron deep
# files = ['vaq-log-trevi-finetuning-3.txt', 'vaq-log-trevi-finetuning-2.txt']
# for file in files:
#     extractFile(file)
with open(filename, 'a') as csvfile:  
    # creating a csv writer object  
    csvwriter = csv.writer(csvfile)  
        
    # writing the fields  
    # csvwriter.writerow(headers)  
        
    # writing the data rows  
    csvwriter.writerows(data) 
# # print(data)
