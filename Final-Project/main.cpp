#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include<vector>
#include<ctime>


using namespace std;

int LinearSearch(vector<string> arr, string x){
    
    int result = -1;
  
    for (int i=0; i<arr.size(); i++){
        
        if(arr.at(i)==x)
            result=i;
        
    }
    
    return result;
       
}

// Returns index of x if it is present in arr[],
    // else return -1
int linearRecursive(vector<string> arr, string x,int size)
    {
    size--;
    int rec;
    if(size>=0){
        if(arr.at(size)==x)
            return size;
        else
            rec=linearRecursive(arr, x,size);
    }
    else
        return -1;
    return rec;
    }



int main()
{
    clock_t search_start,search_end;
    float searchruntime=0.0;
    
    clock_t search_start1,search_end1;
    float searchruntime1=0.0;
    
    string wordToFind, fileName;
    
    
    cout<<"Enter the full name of the file: ";
    cin>>fileName;
    
    cout<<"Enter the word to find in the file: ";
    cin>>wordToFind;
    
    cout<<endl<<"============================================================================="<<endl;
    
    
    vector<string> arr;
    string line;
    ifstream myfile (fileName);
    if (myfile.is_open())
    {
        while (! myfile.eof() )
        {
            getline (myfile,line);
            arr.push_back(line);
        }
        myfile.close();
        search_start=clock();
        int result = LinearSearch(arr, wordToFind);
        search_end=clock();
        if (result == -1)
            cout << ("Linear Search: Element not present")<<endl;
        else
            cout << "Linear Search: Element '"<<wordToFind<<"' is found at line: " << result+1<<endl;
       
        searchruntime=((float)search_end-(float)search_start);
        cout<<"Linear Search time: "<<searchruntime<<" ms (Milliseconds)"<<endl;
        
        cout<<endl<<"******************************************"<<endl;
        
        int n = arr.size();
        
        search_start1=clock();
        int result1 = linearRecursive(arr, wordToFind,n);
        search_end1=clock();
        
               if (result1 == -1)
                   cout << ("Linear Recursice: Element not present")<<endl;
               else
                   cout << ("Linear Recursice: Element found at index ") << result+1<<endl;
        searchruntime1=((float)search_end1-(float)search_start1);
        cout<<"Linear Recursive Search time: "<<searchruntime1<<" ms (Milliseconds)"<<endl;
    }
    else cout << "can't open the file";
    cout<<endl<<"============================================================================="<<endl;
    system("PAUSE");
    
  
  
         
    return 0;
}
