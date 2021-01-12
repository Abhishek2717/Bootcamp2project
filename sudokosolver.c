int n = 9;
int sqrt1(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(i*i==n)
        return i;
    }
    return 0;
}
int check(int i,int j,int arr[n][n],int k)
{
    int l,m,p;
    for(l=0;l<=j-1;l++)
        if(arr[i][l]==k)
        {
            return 0;
        }

    for(l=j+1;l<n;l++)
        if(arr[i][l]==k)
        {
            return 0;
        }

    for(l=0;l<=i-1;l++)
        if(arr[l][j]==k)
        {

            return 0;
        }

    for(l=i+1;l<n;l++)
        if(arr[l][j]==k)
        {
            return 0;
        }

    int o=sqrt1(n);
    for(m=0;m<o;m++)
    {
        for(p=0;p<o;p++)
            if(arr[m+i-i%o][p+j-j%o]==k)
            {
                return 0;
            }
    }
    return 1;
}
int solve(int arr[n][n])
{
    int l=1,m=0,o=0,p=0,i,j,k;
    int arr1[n*n],arr2[n*n],arr3[n*n];
    for(i=0;i<n;i++)
    {

        for(j=0;j<n;j++)
        {

            if(arr[i][j]==0)
            {

                for(k=l;k<=n;k++)
                {

                    if(check(i,j,arr,k)==1)
                    {

                        arr[i][j]=k;

                        arr1[m]=k;
                        m++;
                        arr2[o]=i;
                        arr3[p]=j;
                        o++;
                        p++;
                        l=1;
                        break;
                    }
                }
                if(k==n+1)
                {

                    if(i==0 && j==0)
                    return 0;

                    arr[arr2[o-1]][arr3[p-1]]=0;
                    i=arr2[o-1];
                    j=arr3[p-1]-1;
                    o--;
                    p--;
                    l=arr1[m-1]+1;
                    m--;
                }


            }
        }
    }
    return 1;
}
int main() {
    int t;
    t = 1;
    while(t--)
    {
        int i,j;
        //scanf("%d",&n);
        int arr[n][n];
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&arr[i][j]);

        if(solve(arr)==1)
        {
            //printf("\n");
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    printf("%d ",arr[i][j]);
                    }
                printf("\n");
            }
        }
        else
        printf("No solution");
    }
}
