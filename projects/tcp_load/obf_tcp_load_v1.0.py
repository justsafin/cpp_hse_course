#!/usr/bin/env python3
Z='INFO'
Y=False
X='store_true'
W=Exception
T=True
S=len
R=RuntimeError
O=int
J=print
I=id
A=None
import numpy as K,asyncio as L,argparse as a,datetime as G,logging as E,socket as P
C=a.ArgumentParser()
C.add_argument('--host',type=str,required=T,help='Host for loading')
C.add_argument('--port',type=O,required=T,help='Port on host')
C.add_argument('--rate',type=O,default=A,help='Rate for loading, NOT SUPPORTED!')
C.add_argument('--parallel',type=O,default=A,help='Count of threads for loading')
C.add_argument('--timeout',type=O,default=A,help='Timeout of w+r operations')
C.add_argument('--keepalive',action=X,default=A,help='Do drop connection in client')
C.add_argument('--infinite',default=Y,action=X,help='Make an infinite cycle from input file')
C.add_argument('--loglevel',default=Z,choices=['DEBUG',Z,'WARNING','ERROR','CRITICAL'],help='Set the logging level')
C.add_argument('input_file',type=str,help='File with queries, line by line')
B=C.parse_args()
if B.rate is not A and B.parallel is not A:raise R('Cannot specify --rate and --parallel simultaniously!')
if B.rate is A and B.parallel is A:raise R('Please, specify --rate or --parallel!')
if B.rate is not A:raise R('--rate is not now supported!')
E.getLogger().setLevel(getattr(E,B.loglevel))
def b():
	def E():
		with open(B.input_file,'r')as C:
			for A in C:
				A=A.strip()
				if not A:continue
				yield A
	C=0;D=0
	while T:
		if not B.infinite and C!=0:yield(A,A)
		for F in E():yield(D,F);D+=1
		C+=1
c=b()
H=0
M=0
D=[]
F=dict()
async def d(reader,writer,q,q_num):A=writer;A.write(q.encode('utf-8'));await A.drain();C=1024;B=await reader.readuntil(b'\n');return B
async def e():
	global H,M;C,O=A,A
	for(J,Q)in c:
		if Q is A:break
		if not B.keepalive or C is A:
			if C is not A:
				C.close()
				if I(C)in F:del F[I(C)]
			try:R=G.datetime.now();N=P.socket(P.AF_INET,P.SOCK_STREAM);N.connect((B.host,B.port));N.setblocking(Y);O,C=await L.open_connection(sock=N);F[I(C)]=N
			except W as K:E.error(f"{J}: Error open connection: {K}");H+=1;continue
		try:S=await L.wait_for(d(O,C,Q,J),B.timeout);D.append((G.datetime.now()-R).total_seconds()*1000);E.info(f"{J}: Success in {D[-1]} ms, data = {S}")
		except TimeoutError as K:E.warning(f"{J}: Timeout: {K}");M+=1
		except W as K:E.error(f"{J}: Error during i/o: {K}");H+=1
	if C is not A:
		C.close()
		if I(C)in F:del F[I(C)]
Q,N=A,A
async def f():
	A=[L.create_task(e())for A in range(B.parallel)];global Q,N;Q=G.datetime.now()
	for C in A:await C
	N=G.datetime.now()
try:L.run(f())
except KeyboardInterrupt:N=G.datetime.now();pass
finally:
	for g in F.values():g.close()
	J(f"Stats:");U=S(D)+H+M;V=(N-Q).total_seconds();J(f"Ok queries = {S(D)}, errors = {H}, timeouts = {M}. Total = {U}");J(f"rps = {U/V}; total time = {V}")
	if S(D)>0:J(f"Avg = {K.mean(D)}, min = {K.min(D)}, max = {K.max(D)}, 99% = {K.percentile(D,99)}")
	else:J('len(TIMES) == 0, no statistics')