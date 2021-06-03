#include "Graph.h"

//Reads the graph input file and instantiates a graph object.
string colors[] = {"skyblue", "skyblue1", "skyblue2", "skyblue3", "skyblue4", "steelblue", "steelblue1", "steelblue2", "steelblue3","steelblue"};
    
Graph::Graph(ifstream& inFS)
{
    int num_vertices = 0;
    int num_edges = 0;
    inFS >> num_vertices;
    inFS >> num_edges;

    string name;
    Vertex curr_vertex;
    for(int i = 0; i < num_vertices; i++)
    {
        inFS >> name;
        curr_vertex = Vertex();
        curr_vertex.label = name;
        vertices.push_back(curr_vertex);
    }

    string vertex1;
    string vertex2;
    for(int i = 0; i < num_edges; i++)
    {
        inFS >> vertex1;
        inFS >> vertex2;
        int v1 = 0;
        int v2 = 0;
        for(Vertex v: vertices)
        {   
            if(v.label == vertex1)
            {
                break;
            }
            v1++;
        }
        for(Vertex v: vertices)
        {   
            if(v.label == vertex2)
            {
                break;
            }
            v2++;
        }
        int weight = 0;
        inFS >> weight;
        vertices.at(v1).neighbors.push_back(make_pair(v2, weight));
        // vertices.at(v2).neighbors.push_back(make_pair(v1, weight));
    }

}//end of graph constructo

Graph::~Graph()
{
    
}//end of destructor

/*Outputs graph object to a .dot file, then makes a system call that calls dotty on this file. 
In the dotty file, each node should include vertex label and its distance value.*/
// void Graph::output_graph(const string & outputFilename)
// {
//     cout<<"test"<<endl;
//     ofstream outFS(outputFilename);
//     if(!outFS.is_open()){
//         cout<<"Error"<<endl;
//         return;
//     }
//     outFS<<"digraph G {"<<endl;
//     for(int i =0; i < vertices.size();i++)
//     {
//         outFS<<vertices.at(i).label<<endl;
//     }
//     for(int i =0; i < vertices.size();i++)
//     {
//         list<pair<int, int> > temp = vertices.at(i).neighbors;
//         for(int j = 0; j < vertices.at(i).neighbors.size(); j++)
//         {
//             outFS<<vertices.at(i).label << " -> " << vertices.at(temp.front().first).label<<endl;
//             temp.pop_front();
//         }
//     }

//     // makeDotty(outFS, 0);
//     outFS<<"}";
//     outFS.close();
//     string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
//     string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
//     system(command.c_str());
// }//emd of output graph

void Graph::output_graph(const string &outputFilename){
 ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,0);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());   
}
void Graph::visualizeTree(ofstream & outFS, int n){
    
    if(vertices[n].color == "BLACK")
        return;
    vertices[n].color = "BLACK";
    outFS << vertices[n].label << "[style = \"filled\", color="<<colors[vertices[n].distance]<<", label=\"" << vertices[n].label << ", " << vertices[n].distance << "\"];" << endl; 
    for(list<pair<int,int>>::const_iterator it = vertices[n].neighbors.begin(); it != vertices[n].neighbors.end(); it++)
    {
        outFS<< vertices[n].label <<" -> " << vertices[(*it).first].label <<";"<<endl;
        visualizeTree(outFS,(*it).first);
    }
}


/*Breadth First Search. Via a BFS traversal, this function should assign each individual vertex's distance 
to the number of hops that the vertex is from the start vertex.*/
void Graph::bfs()
{
    for(Vertex v: vertices)
    {
        v.color = "WHITE";              // undiscovered
        v.distance = INT_MAX;           //infinity by default
        v.prev = nullptr;                   //previous vertex
    }
    
    queue<Vertex> discovered;
    vertices.at(0).color = "GRAY";
    vertices.at(0).distance = 0; 
    discovered.push(vertices.at(0));
        // cout<<"TEST"<<endl;
    Vertex current;
    while(!discovered.empty())
    {
        //queue<Vertex> discovered_copy = discovered;
        // while(!discovered_copy.empty())
        // {
        //     cout<<discovered_copy.front().label<<" ";
        //     discovered_copy.pop();
            
        // }
        //cout<<endl;
        current = discovered.front();
        discovered.pop();
        list<pair<int, int> > tempNeighbors = current.neighbors;
        while(!tempNeighbors.empty())
        {
            Vertex* found = &vertices.at(tempNeighbors.front().first);
            if(found->color == "WHITE")
            {
                found->color = "GRAY";// discovered, but not expanded
                found->distance = current.distance + 1;
                found->prev = &current;
                discovered.push(*found);
            }
            tempNeighbors.pop_front();
        }
        //cout<<"discovered size "<<discovered.size()<<endl;
        current.color =  "BLACK";  
    }
}//end of bfs