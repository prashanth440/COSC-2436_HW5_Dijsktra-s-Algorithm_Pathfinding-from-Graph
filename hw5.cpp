#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stack>
#include "hw5Functions.h"
#include "ArgumentManager.h"
using namespace std;

int main(int argc, char * argv[])
{
    ifstream fileInput, pathInput;
    ofstream fileOutput;
    //fileInput.open("/Users/saiprashanthharihar/Desktop/hw5-archive/input51.txt");
    //pathInput.open("/Users/saiprashanthharihar/Desktop/hw5-archive/path51.txt");
    //fileOutput.open("/Users/saiprashanthharihar/Desktop/hw5Output.txt");
    
    if (argc < 2)
    {
        return -1;
    }
      
    ArgumentManager am(argc, argv);
    std::string infilename = am.get("input");
    std::string pathFile = am.get("path");
    std::string outfilename = am.get("output");
    
    fileInput.open(infilename);
    pathInput.open(pathFile);
    fileOutput.open(outfilename);
    
    int source, destination, i, j, a, b;
    float weight;
    vector<float> paths, weights;
    vector<int> src, des;
    pathInput >> source >> destination;
    
    while(!fileInput.eof())
    {
        fileInput >> a >> b;
        fileInput >> weight;
        src.push_back(a);
        des.push_back(b);
        weights.push_back(weight);
    }

    int N = (int) src.size() + 10;
    float **arr = new float *[N];
    bool *visited = new bool[N];
    for(i = 0; i < N; i++)
    {
        arr[i] = new float[N];
        visited[i] = false;
    }
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            arr[i][j] = 10008;
        }
    }
    for(i = 0; i < (int) weights.size(); i++)
    {
        if(src[i] < N && des[i] < N)
        {
            arr[src[i]][des[i]] = weights[i];
        }
    }
   
    if(pathSumMin(source, destination, visited, arr, N) == 10008)
    {
        //cout << "Infinite" << endl << "Infinite" << endl << "0" << endl;
        fileOutput << "Infinite" << endl << "Infinite" << endl << "0" << endl;
    }
    else if(source == destination)
    {
        //cout << "0" << endl << "0" << endl << "1" << endl;
        fileOutput << "0" << endl << "0" << endl << "1" << endl;
    }
    else
    {
        //cout << pathSumMin(source, destination, visited, arr, N) << endl;
        fileOutput << pathSumMin(source, destination, visited, arr, N) << endl;
    
        for(i = 0; i < N; i++)
        {
            if(src[i] < N && des[i] < N)
            {
                arr[src[i]][des[i]] = (-1)*weights[i];
            }
        }
    
        //cout << (-1)*pathSumMax(source, destination, visited, arr, N) << endl;
        fileOutput << (-1)*pathSumMax(source, destination, visited, arr, N) << endl;
    
        int count = 0;
        for(i = 0; i < N; i++)
        {
            visited[i] = false;
        }
    
        pathCounter(source, destination, count, visited, arr, N);
        //cout << count << endl;
        fileOutput << count << endl;
    }
    
    
    delete [] visited;
    for(i = 0; i < N; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
    fileInput.close();
    pathInput.close();
    fileOutput.close();
}
