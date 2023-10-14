#include <cstdio>
#include <cstring>

using namespace std;

int dp[2][0x10000][2];

int main( void ) {
   int n;
   scanf( "%d", &n );
   
   int curr = 0, next = 1;

   memset( dp[curr], 0x3F, sizeof dp[curr] );
   dp[curr][0][0] = 0;
   
   for( int r = 0; r < n; ++r ) {
      static char buff[16+1];
      scanf( "%s", buff );
      for( int c = 0; c < 16; ++c ) {
         int val = buff[c]-'0';
         memset( dp[next], 0x3F, sizeof dp[next] );
         
         for( int hor = 0; hor < 2; ++hor ) {
            for( int mask = 0; mask < 0x10000; ++mask ) {
               for( int h = 0; h < 2; ++h ) {
                  int v = h^val;

                  int cost = dp[curr][mask][hor];
                  if( h && (!c || !hor) ) ++cost;
                  if( v && !(mask>>c&1) ) ++cost;
                  
                  dp[next][mask & ~(1<<c) | (v<<c)][h] <?= cost;
               }
               
            }
         }
         curr ^= 1;
         next ^= 1;
      }
   }

   int ret = 1000000000;
   for( int hor = 0; hor < 2; ++hor ) 
      for( int mask = 0; mask < 0x10000; ++mask ) 
         ret <?= dp[curr][mask][hor];
   printf( "%d\n", ret );

   return 0;
}
