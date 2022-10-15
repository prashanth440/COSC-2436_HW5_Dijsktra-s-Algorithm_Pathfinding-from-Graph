#ifndef hw5Functions_h
/*
 Sources:
 1) https://www.geeksforgeeks.org/minimum-cost-of-simple-path-between-two-nodes-in-a-directed-and-weighted-graph/
 2) https://www.geeksforgeeks.org/count-possible-paths-two-vertices/
 */
#define hw5Functions_h
#include <iostream>
#include <string>
#include <vector>
using namespace std;

float pathSumMin(int source, int destination, bool *visited, float **arr, int N)
{
    if(source == destination)
    {
        return 0;
    }
    visited[source] = true;
    float sum = 10008;
    
    for(int i = 0; i < N; i++)
    {
        if(arr[source][i] != 10008 && visited[i] == false)
        {
            float current = pathSumMin(i, destination, visited, arr, N);
            if(current < 10008)
            {
                sum = min(sum, arr[source][i] + current);
            }
        }
    }
    visited[source] = false;
    return sum;
}



float pathSumMax(int source, int destination, bool *visited, float **arr, int N)
{
    if(source == destination)
    {
        return 0;
    }
    visited[source] = true;
    float sum = 10008;
    
    for(int i = 0; i < N; i++)
    {
        if(arr[source][i] != 10008 && visited[i] == false)
        {
            float current = pathSumMax(i, destination, visited, arr, N);
            if(current < 10008)
            {
                sum = min(sum, arr[source][i] + current);
            }
        }
    }
    
    visited[source] = false;
    return sum;
}


void pathCounter(int source, int destination, int &count, bool *visited, float **arr, int N)
{
    visited[source] = true;
    if(source == destination)
    {
        count++;
    }
    else
    {
        for(int i = 0; i < N; i++)
        {
            if(arr[source][i] < 10008 && visited[i] == false)
            {
                pathCounter(i, destination, count, visited, arr, N);
            }
        }
    }
    visited[source] = false;
}
#endif /* hw5Functions_h */
