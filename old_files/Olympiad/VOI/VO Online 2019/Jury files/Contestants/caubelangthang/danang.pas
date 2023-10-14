uses math;
const fi='danang.inp'; fo='danang.out';
      maxN=trunc(2e5);
      maxM=trunc(2e5);
      oo=trunc(1e9);
type tapE=record
            u,v,c: int32;
        end;
var n,m,r,nheap: int32;
    res: int64;
    e: array[0..maxM] of tapE;
    adj,bdj: array[0..2*maxM] of int32;
    head,deg,pos,heap,d,trace: array[0..maxN] of int32;
    free: array[0..maxN] of boolean;
procedure sort(l,r: int32);
var i,j: int32;
    k,t: tapE;
begin
    i:=l; j:=r;
    k:=e[l+random(r-l+1)];
    repeat
        while (e[i].u<k.u) or ((e[i].u=k.u) and (e[i].v<k.v)) do inc(i);
        while (e[j].u>k.u) or ((e[j].u=k.u) and (e[j].v>k.v)) do dec(j);
        if i<=j then begin
            t:=e[i];
            e[i]:=e[j];
            e[j]:=t;
            inc(i);
            dec(j);
        end;
    until i>j;
    if i<r then sort(i,r);
    if l<j then sort(l,j);
end;

procedure luocanh;
var i,mm: int32;
begin
    mm:=0;
    for i:=1 to m do begin
        e[mm+1]:=e[i];
        if (e[i].u<>e[i+1].u) or (e[i].v<>e[i+1].v) then inc(mm);
    end;
    m:=mm;
end;

procedure nhap;
var i: int32;
begin
    readln(n,m,r);
    for i:=1 to m do with e[i] do readln(u,v,c);
    sort(1,m);
    luocanh;
    for i:=1 to m do with e[i] do begin
        inc(deg[u]);
        inc(deg[v]);
    end;
    head[0]:=1;
    for i:=1 to n do head[i]:=head[i-1]+deg[i-1];
    for i:=1 to m do with e[i] do begin
        adj[head[u]]:=v;
        adj[head[v]]:=u;
        bdj[head[u]]:=c;
        bdj[head[v]]:=c;
        inc(head[u]);
        inc(head[v]);
    end;
end;

procedure update(u: int32);
var c,r: int32;
begin
    c:=pos[u];
    if c=0 then begin
        inc(nheap);
        c:=nheap;
    end;
    while (c>1) do begin
        r:=c div 2;
        if d[heap[r]]<=d[u] then break;
        heap[c]:=heap[r];
        pos[heap[c]]:=c;
        c:=r;
    end;
    heap[c]:=u;
    pos[u]:=c;
end;

function pop: int32;
var u,c,r: int32;
begin
    pop:=heap[1];
    u:=heap[nheap];
    dec(nheap);
    r:=1;
    while (r*2<=nheap) do begin
        c:=r*2;
        if (c<nheap) and (d[heap[c+1]]<d[heap[c]]) then inc(c);
        if d[u]<=d[heap[c]] then break;
        heap[r]:=heap[c];
        pos[heap[r]]:=r;
        r:=c;
    end;
    heap[r]:=u;
    pos[u]:=r;
end;

procedure dijkstra;
var i,u,iv,v: int32;

begin
    fillchar(free,sizeof(free),true);
    fillchar(trace,sizeof(trace),0);
    fillchar(pos,sizeof(pos),0);
    for i:=1 to n do d[i]:=oo;
    d[1]:=-oo;
    nheap:=0;
    update(1);
    repeat
        u:=pop;
        if u=n then break;
        free[u]:=false;
        for iv:=head[u-1] to head[u]-1 do begin
            v:=adj[iv];
            if free[v] then begin
                if bdj[iv]>=d[u]+r then begin
                    if bdj[iv]<d[v] then begin
                        d[v]:=bdj[iv];
                        update(v);
                        trace[v]:=u;
                    end;
                end;
            end;
        end;
    until nheap=0;
end;

procedure truyvet;
var u,v,iv: int32;
begin
    u:=n;
    res:=0;
    while (trace[u]>0) do begin
        v:=trace[u];
        for iv:=head[u-1] to head[u]-1 do begin
            if v=adj[iv] then begin
                res:=res+int64(bdj[iv]);
                break;
            end;
        end;
        u:=trace[u];
    end;
end;

procedure xuli;
begin
    dijkstra;
    res:=-1;
    if d[n]<>oo then truyvet;
    writeln(res);
end;

begin
    assign(input,fi); reset(input);
    assign(output,fo); rewrite(output);
    nhap;
    xuli;
    close(input); close(output);
end.
