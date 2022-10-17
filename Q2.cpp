#include <iostream>


using namespace std;

struct point {
    int number, index;
};
struct point find_max(int arr[] ,int n ){
    int i;
    struct point max ;
    max.number=arr[0];
    max.index=0;
    for (i=1 ; i<n ; i++){
        if(arr[i]>max.number){
             max.number=arr[i];
             max.index=i;
        }
    }
    return max ;
}
struct point find_min(int arr[] ,int n ){
     int i;
    struct point min ;
    min.number=arr[0];
    min.index=0;
    for (i=1 ; i<n ; i++){
        if(arr[i]<min.number){
             min.number=arr[i];
             min.index=i;
        }
    }
    return min ;
}

int is_empty_left(int arr[],int n ){
    int flag=1;
    int i;
    for(i=0;i<n;i++){
        if(arr[i]!=0){
            flag=0;
        }
    }
    return flag;
}
int is_empty_right(int arr[],int n ){
    int flag=0;
    int i;
    for(i=0;i<n;i++){
        if(arr[i]!=1000){
            flag=1;
        }
    }
    return flag;
}
int find_cost(int arr1[],int parr1[],int arr2[],int parr2[],int n1,int n2){
    int cost=0 , flag=1 ;

    while(flag){
        struct point  max = find_max(arr1 ,n1 );
        struct point  min = find_min(arr2 ,n2 );
        if (max.number<min.number){
            flag=0;
            break;
        }else{
            if( parr1[max.index]>=parr2[min.index]){
                cost=cost+ parr2[min.index];
                arr2[min.index]=1000;
            }else{
                cost=cost+ parr1[max.index];
                arr1[max.index]=0;
            }
            int flag1=0,flag2=0;
            flag1=is_empty_left(arr1,n1);
            flag2=is_empty_left(arr2,n2);
            if(flag1 || flag2){
                flag=0;
            }


        }

    }
    return cost ;
}



int main(  )
{
    int n,j,i;
    cin>>n;
    int arr[n] ,parr[n];
    for(j=0;j<n;j++){
            cin >> arr[j];
        }
    for(j=0;j<n;j++){
            cin >> parr[j];
            }

    int cost,min_cost=1000;
    for(i=0;i<n-1;i++){
            int arr1[i+1],arr2[n-(i+1)],parr1[i+1],parr2[n-(i+1)];
            for(j=0;j<i+1;j++){
                arr1[j]=arr[j];
                parr1[j]=parr[j];
            }
    for(j=0;j<n-(i+1);j++){
                arr2[j]=arr[j+i+1];
                parr2[j]=parr[j+i+1];
            }

    cost=find_cost(arr1,parr1,arr2,parr2,i+1,n-(i+1));

    if(cost<min_cost){
        min_cost=cost;
    }
    }
    cout<< min_cost;

    return 0;

}


