{$MODE OBJFPC}
const
    fi='danang.inp';
    fo='danang.out';
    lim=trunc(1e5)*2;
    oo=trunc(1e9)+1;
type
    TLabel=record
        l,pre: longint;
    end;
    TAdjNode=record
        v,w,link: longint;
    end;
var
    adj: array[1..2*lim] of TAdjNode;
    head: array[1..2*lim] of longint;
    avail: array[1..lim] of boolean;
    d: array[0..lim] of Tlabel;
    n,m,p: longint;
    procedure enter;
    var
        f: text;
        i,u: longint;
    begin
        assign(f,fi);
        reset(f);
        readln(f,n,m,p);
        fillchar(head[1],n*sizeof(head[1]),0);
        for i:=1 to m do
        begin
            readln(f,u,adj[i].v,adj[i].w);
            adj[i].link:=head[u];
            head[u]:=i;
        end;
        close(f);
        assign(f,fi);
        reset(f);
        readln(f);
        for i:=m+1 to 2*m do
        begin
            readln(f,adj[i].v,u,adj[i].w);
            adj[i].link:=head[u];
            head[u]:=i;
        end;
        close(f);
    end;
    procedure init;
    var v: longint;
    begin
        for v:=0 to n do
            d[v].l:=oo;
        d[1].l:=0;
        fillchar(avail[1], n*sizeof(avail[1]), 1);
    end;
    procedure relax(u,v,w: longint);
    begin
        if (d[v].l>d[u].l+w) and (d[u].pre+p<=w) then
        begin
            d[v].l:=d[u].l+w;
            d[v].pre:=w;
        end;
    end;
    procedure Dijkstra;
    var
        u,v,i: longint;
    begin
        repeat
            u:=0;
            for v:=1 to n do
                if avail[v] and (d[v].l<d[u].l) then
                    u:=v;
            if (u=0) or (u=n) then  break;
            avail[u]:=false;
            i:=head[u];
            while i<>0 do
            begin
                relax(u,adj[i].v,adj[i].w);
                i:=adj[i].link;
            end;
        until false;
    end;
    procedure printresult;
    var
        f: text;
    begin
        assign(f,fo);
        rewrite(f);
        if d[n].l=oo then
            write(f,-1)
        else    write(f,d[n].l);
        close(f);
    end;
begin
    enter;
    init;
    Dijkstra;
    printresult;
end.