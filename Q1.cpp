#include <iostream>



using namespace std;

void mergesort(int arr[]){
    int  temp;
    int seq1[4];
    if(arr[0]>arr[1]){
        temp=arr[1];
        arr[1]=arr[0];
        arr[0]=temp;
    }
    if(arr[2]>arr[3]){
        temp=arr[3];
        arr[3]=arr[2];
        arr[2]=temp;
    }
    if(arr[0]<arr[2]){
        seq1[0]=arr[0];
            if(arr[1]<arr[2]){
                seq1[1]=arr[1];
                seq1[2]=arr[2];
                seq1[3]=arr[3];
            }else{
                seq1[1]=arr[2];
                if(arr[1]<arr[3]){
                    seq1[2]=arr[1];
                    seq1[3]=arr[3];
                }else{
                    seq1[2]=arr[3];
                    seq1[3]=arr[1];
                }
            }

    }else{
        seq1[0]=arr[2];
        if(arr[0]<arr[3]){
            seq1[1]=arr[0];
             if(arr[1]<arr[3]){
                seq1[2]=arr[1];
                seq1[3]=arr[3];
             }else{
                seq1[3]=arr[1];
                seq1[2]=arr[3];
             }
        }else{
            seq1[1]=arr[3];
            seq1[2]=arr[0];
            seq1[3]=arr[1];
        }

    }
    int j;
     for(j=0;j<4;j++){
           arr[j]=seq1[j];
        }

}


int main( )
{
    long int n ;
    int i,j;
    cin>>n;

    for(i=0 ; i<n;i++){
            int arr[4];
        for(j=0;j<4;j++){
            cin >> arr[j];
        }
        mergesort(arr);
        /*for(j=0;j<4;j++){
            cout<< arr[j];
        }*/
        cout<<(min(arr[0],arr[1])*min(arr[2],arr[3]) );
        cout<<"\n";
    }
    return 0;

}


