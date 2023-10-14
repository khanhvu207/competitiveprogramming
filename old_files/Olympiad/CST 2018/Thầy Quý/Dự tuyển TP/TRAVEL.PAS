uses math;
const fi = 'TRAVEL.INP';
      fo = 'TRAVEL.OUT';

var ans: int64;
    i,k,n,s,u,v,can: longint;
    a,b,c: array [1..50000] of longint;
    it,lz: array [1..4*50000] of longint;

procedure sort(l,r: longint);
  var i,j,x,t: longint;
  begin
      i:=l; j:=r; x:=b[(l+r) div 2];
      repeat
          while b[i] < x do inc(i);
          while x < b[j] do dec(j);
          if not(i>j) then
            begin
                t:=a[i]; a[i]:=a[j]; a[j]:=t;
                t:=b[i]; b[i]:=b[j]; b[j]:=t;
                t:=c[i]; c[i]:=c[j]; c[j]:=t;
                inc(i); dec(j);
            end;
      until i>j;
      if l<j then sort(l,j);
      if i<r then sort(i,r);
  end;


procedure init;
  var f: text;
      i: longint;
  begin
      assign(f,fi); reset(f);
      read(f,k,n,s);
      for i:=1 to k do read(f,a[i],b[i],c[i]);
      close(f);
      sort(1,k);
  end;

procedure out;
  var f: text;
  begin
      assign(f,fo); rewrite(f); writeln(f,ans); close(f);
  end;


function get(i,l,r: longint): int64;
  var mid,q,p: longint;
  begin
      if lz[i] <> 0 then
        begin
            if l<>r then
              begin
                  inc(lz[2*i], lz[i]);
                  inc(lz[2*i+1], lz[i]);
              end;
            it[i]:= it[i] + lz[i];
            lz[i]:=0;
        end;

      if (v < l) or (r < u) then exit(0);
      if (u <= l) and (r <= v) then exit(it[i]);

      mid:=(l+r) div 2;
      p:= get(2*i, l, mid);
      q:= get(2*i+1, mid+1, r);
      exit(max(q,p));
  end;

procedure update(i,l,r,val: longint);
  var mid: longint;
  begin
      if lz[i] <> 0 then
        begin
            if l<>r then
              begin
                  inc(lz[2*i], lz[i]);
                  inc(lz[2*i+1], lz[i]);
              end;
            it[i]:= it[i] + lz[i];
            lz[i]:=0;
        end;

      if (v < l) or (r < u) then exit;
      if (u <= l) and (r <= v) then
        begin
            it[i]:= it[i] + val;
            if l<>r then
              begin
                  inc(lz[2*i], val);
                  inc(lz[2*i+1], val);
              end;
            exit;
        end;

      mid:=(l+r) div 2;
      update(2*i, l, mid,val); update(2*i+1, mid+1, r, val);
      it[i]:= max(it[2*i] , it[2*i+1]);
  end;


BEGIN
    init;

    ans:=0;
    fillchar(lz,sizeof(lz),0);
    for i:=1 to k do
      begin
          u:=a[i]; v:=b[i]-1;
          can:=s - get(1,1,n);
          if can >= c[i] then
            begin
                update(1,1,n,c[i]);
                ans:= ans + c[i];
            end
          else begin
                   update(1,1,n,can);
                   ans:= ans + can
               end;
      end;

    out;
END.
