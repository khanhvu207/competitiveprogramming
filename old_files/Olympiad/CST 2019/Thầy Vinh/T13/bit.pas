const 
   inf = 1000000000;

var
   dp : array[1..2, 0..65535, 0..1] of longint;
   n  : longint;
   curr, next : longint;
   r, c, hor, h, v, val : longint;
   mask : longint;
   row : array[0..15] of char;
   ret, cost : longint;

procedure init( x : longint );
var
   mask, hor : longint;
begin
   for hor := 0 to 1 do 
      for mask := 0 to 65535 do
         dp[x, mask, hor] := inf;
end;

procedure mini( var a, b : longint );
begin
   if b < a then a := b;
end;

begin
   readln( n );
   
   curr := 1; next := 2;

   init( curr );
   dp[curr, 0, 0] := 0;

   for r := 1 to n do begin;   
      readln( row );
      for c := 0 to 15 do begin
         val := ord( row[c] ) - ord( '0' );

         init( next );

         for hor := 0 to 1 do begin
            for mask := 0 to 65535 do begin
               for h := 0 to 1 do begin
                  v := h xor val;

                  cost := dp[curr, mask, hor];
                  if (h = 1) and ((c = 0) or (hor = 0)) then cost := cost + 1;
                  if (v = 1) and (((mask shr c) and 1) = 0) then cost := cost + 1;
                  
                  mini( dp[next, mask and (65535 xor (1 shl c)) or (v shl c), h], cost );
               end;
            end;
         end;
         curr := 3 - curr;
         next := 3 - next;
      end;
   end;

   ret := 1000000000;
   
   for hor := 0 to 1 do
      for mask := 0 to 65535 do
         mini( ret, dp[curr, mask, hor] );

   writeln( ret );
end.
