#include <stdio.h>

void main()
{
     int W,curr_w,maxi,n;
     int used[10];
     int weight[10];
     int val[10];
     float tot_val;
     int i;
     
     printf("Enter the knapsack capacity:\n");
     scanf("%d",&W);
     printf("Enter the no of items:\n");
     scanf("%d",&n);
     printf("Enter the weight and value for %d item:\n",n);
     for(i=0;i<n;i++)
     {
      printf("Weight [%d]\t",i+1);
      scanf("%d",&weight[i]);
      printf("Value [%d]\t",i+1);
      scanf("%d",&val[i]);
     }
     
     //printf("Weight\n%d\t Value\n%d\t",weight[i],val[i]);
     
     for(i=0;i<n;++i)
     {
          used[i]=0; //since no ith item has been used
     }
     
     curr_w=W;
     while(curr_w>0)
     {
          maxi=-1;//finding the best item to put in bag
          for(i=0;i<n;++i)
          {
               if((used[i]==0)&&((maxi==-1) || ((float)val[i]/weight[i] > (float)val[maxi]/weight[maxi])))
               {
                    maxi=i; 
               }
          }
          used[maxi]=1; //item already in the bag
          curr_w-=weight[maxi];//one one item going to be less if put in the bag
          tot_val+=val[maxi];
          
          if(curr_w>=0)
          {
               printf("Added item %d with (%d kg,%d Rs) completely in bag\n",maxi+1,weight[maxi],val[maxi]);
               printf("Capacity left: %d\n",curr_w);
          }
          else{
          printf("Added %d percent of item %d with(%d kg, %d Rs) in the bag\n",(int)((1+(float)curr_w/weight[maxi])*100),maxi+1,weight[maxi], val[maxi]);
          tot_val -= val[maxi];
          tot_val += (1 + (float)curr_w/weight[maxi]) * val[maxi]; //adding that percent of value in the bag as left
          }
     }
     printf("Filled the bag with objects worth %.2f Rs\n", tot_val);
}
