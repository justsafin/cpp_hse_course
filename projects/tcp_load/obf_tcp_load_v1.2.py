#!/usr/bin/env python3

# Скрипт нагрузки сервера
# Считает, что запрос - 1 строка, и сервер понимает \n как разделитель
# Аналогично, ответы делит тоже по \n

Z='INFO'
Y=False
X='store_true'
W=Exception
S=True
R=len
Q=RuntimeError
N=int
J=print
I=id
A=None
import asyncio as L,argparse as a,datetime as E,logging as F,statistics as T,socket as O
C=a.ArgumentParser()
C.add_argument('--host',type=str,required=S,help='Host for loading')
C.add_argument('--port',type=N,required=S,help='Port on host')
C.add_argument('--rate',type=N,default=A,help='Rate for loading, NOT SUPPORTED!')
C.add_argument('--parallel',type=N,default=A,help='Count of threads for loading')
C.add_argument('--timeout',type=N,default=A,help='Timeout of w+r operations')
C.add_argument('--keepalive',action=X,default=A,help='Do drop connection in client')
C.add_argument('--infinite',default=Y,action=X,help='Make an infinite cycle from input file')
C.add_argument('--loglevel',default=Z,choices=['DEBUG',Z,'WARNING','ERROR','CRITICAL'],help='Set the logging level')
C.add_argument('input_file',type=str,help='File with queries, line by line')
B=C.parse_args()
if B.rate is not A and B.parallel is not A:raise Q('Cannot specify --rate and --parallel simultaniously!')
if B.rate is A and B.parallel is A:raise Q('Please, specify --rate or --parallel!')
if B.rate is not A:raise Q('--rate is not now supported!')
F.getLogger().setLevel(getattr(F,B.loglevel))
def b():
	def D():
		with open(B.input_file,'r')as C:
			for A in C:
				A=A.strip()
				if not A:continue
				yield A
	C=0
	while S:
		for E in D():yield(C,E);C+=1
		if not B.infinite:return A,A
c=b()
H=0
M=0
D=[]
G=dict()
async def d(reader,writer,q,q_num):B=b'\n';A=writer;A.write(q.encode('utf-8')+B);await A.drain();D=1024;C=await reader.readuntil(B);return C
async def e(clid):
	global H,M;C,P=A,A
	for(J,Q)in c:
		if Q is A:break
		if not B.keepalive or C is A:
			if C is not A:
				C.close()
				if I(C)in G:del G[I(C)]
			try:R=E.datetime.now();N=O.socket(O.AF_INET,O.SOCK_STREAM);N.connect((B.host,B.port));N.setblocking(Y);P,C=await L.open_connection(sock=N);G[I(C)]=N
			except W as K:F.error(f"{J}: Error open connection: {K}");H+=1;continue
		try:
			if B.keepalive:R=E.datetime.now()
			S=await L.wait_for(d(P,C,Q,J),B.timeout);D.append((E.datetime.now()-R).total_seconds()*1000);F.info(f"{J}: Success in {D[-1]} ms, data = {S}")
		except TimeoutError as K:F.warning(f"{J}: Timeout: {K}");M+=1
		except W as K:F.error(f"{J}: Error during i/o: {K}");H+=1
	if C is not A:
		C.close()
		if I(C)in G:del G[I(C)]
P,K=A,A
async def f():
	A=[L.create_task(e(A))for A in range(B.parallel)];global P,K;P=E.datetime.now()
	for C in A:await C
	K=E.datetime.now()
try:L.run(f())
except KeyboardInterrupt:K=E.datetime.now();pass
finally:
	for g in G.values():g.close()
	J(f"Stats:");U=R(D)+H+M;V=(K-P).total_seconds();J(f"Ok queries = {R(D)}, errors = {H}, timeouts = {M}. Total = {U}");J(f"rps = {U/V}; total time = {V}")
	if R(D)>0:J(f"Avg = {T.mean(D)}, min = {min(D)}, max = {max(D)}, 99% = {T.quantiles(D,n=100,method='inclusive')[98]}")
	else:J('len(TIMES) == 0, no statistics')
