#include<iostream.h>

int i,j,n,f=0,r=0,q[10],a[10][10],vis[10];
void bfs(int u)
{
int v;
vis[u]=1;
q[r]=u;
while(f<=r)
{
u=q[f++];
for(v=1;v<=n;v++)
if(a[u][v]&&!vis[v])
{
vis[v]=1;
q[++r]=v;
}
}
}
void main()
{
int src;

printf("\nEnter no.of vertices: ");
scanf("%d",&n);
printf("Enter adjacency matrix\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
printf("Enter the source vertex: ");
scanf("%d",&src);
for(i=0;i<=n;i++)
vis[i]=0;
bfs(src);
printf("From vertex %d, the vertices\n",src);
for(i=1;i<=n;i++)
if(vis[i])
printf("%d is reachable\n",i);

}