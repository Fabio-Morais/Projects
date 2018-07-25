# -*- coding: utf-8 -*-
"""
Laboratórios de Matemática 2
Parte 1 - Versão 3
Data: 2017/03/12
Autores
1. 1160772 Diogo Silva
2. 1161291 Fábio Morais
3. 1161266 Marcelo Pais
4. 1150670 Iuri Figueiredo
"""
from __future__ import division
from __future__ import print_function
from LabMat1_Lib import *
import pylab as pl
clc()

#%% Bloco de identificação do trabalho
print('\n\nTrabalho curricular\nPARTE 1\nVERSÃO 3\n\n')
print('AUTORES:')
print('\t 1160772 \t Diogo Silva')
print('\t 1161291 \t Fábio Morais')
print('\t 1161266 \t Marcelo Pais')
print('\t1150670 \t Iuri Figueiredo')
#%% Funçoes 
def descarga_carga(local,Vin,T,Vc):
    n=symbols('n',positive=True,integer=True);t=sym('t')    
    cont=0
    cont2=0    
    flag=0
    cont3=0
    for i in range(0,local):
        flag=0
        for j in range(cont2,len(Vin)):
            if(Vin[j]==0):
                if(flag==0):
                    cont=j
                    flag=1
                    break;
        flag=0     
        for j in range(cont,len(Vin)):
            if(Vin[j]!=0):
                if(flag==0):
                    cont3=j
                    flag=1
                    break;
        flag=0
        for j in range(cont3,len(Vin)):
            if(Vin[j]==0):
                if(flag==0):
                    cont2=j
                    flag=1
                    break;
    t1=[]
    pl.plot(T,Vin,'--',label='Tensao em vin')
    pl.plot(T,Vc,label='Tensao em vc')
    pl.plot(T[cont],Vin[cont],'om',label='Td')    
    pl.plot(T[cont3],Vin[cont3],'oc',label='Tc')     
    pl.plot(T[cont2-1],Vin[cont2-1],'or',label='Tcf')       
    title("Grafico 1")
    pl.xlabel('Tempo/s')
    pl.ylabel('Tensao/V')
    axis([T[0],T[-1],min(Vin)-1,max(Vin)+6])
    grid('on')
    legend()
    show()    
    t1.append(cont);t1.append(cont3);t1.append(cont2-1)
    return t1

#%% Importaçao do ficheiro
disp("Exercicio 1")
t=sym('t');n,N=symbols('n,N',positive=True,integer=True)
T=[];Vin=[];Vc=[]
database=open('Dados_TC_P1_V3.txt','r')#Passagem do documento  txt para o python 
for line in database:                                   
         line=line.strip()
         X,Y,Z=line.split()
         T.append(float(X))
         Vin.append(float(Y))
         Vc.append(float(Z))
database.close()
#%% Defenir variaveis
tau_s,T1=sym('tau_s,T1')
t1=[]
R=1*10**6;C=1.1*10**(-6);tau=R*C # dados do problema
m=inline(t-T1*floor((t-tau_s)/T1),(t,tau_s,T1))# defenir funçao modulos
t1=descarga_carga(2,Vin,T,Vc)# descubrir intate de carga, descarga e final de carga
V0=NE(min(Vin),0)# valor minimo de vin
Vm=NE(max(Vin),0)#valor maximo de vin
Td=NE(T[t1[0]],0)#valor do tempo inicial da  descarga
Tc=NE(T[t1[1]],0)#valor do tempo inicial da  carga
Tcf=NE(T[t1[2]],0)#valor do tempo final da  carga
#%% Defenir Vin
Ven=inline(Piecewise((0,t<Td),(V0,t<Tc),(Vm,t<Tcf),(0,t>Tcf)),t)#fazer a defeniçao da funçao no periodo em questao
Venp=inline(Ven(m(t,Td,Tcf-Td)),t)# utilizar a funçao modulos para poder replicar esse periodo em todo o seu dominio
#%% V de saida
Vcc=inline(Vm*(1-exp((-t+Tc)/tau)),t)#expresao de carga do condençador
Vd=NE(Vc[t1[0]],1)
Vdc=inline(Vd*exp((-t+Td)/tau),t)#expreçao de descarga
Vcd=inline(Piecewise((0,t<Td),(Vdc(t),t<Tc),(Vcc(t),t<Tcf),(0,t>Tcf)),t)#fazer a defeniçao da funçao no periodo em questao
Vcdp=inline(Vcd(m(t,Td,Tcf-Td)),t)# utilizar a funçao modulos para poder replicar esse periodo em todo o seu dominio
#%% Potencia
tau0=Td;T0=NE(Tcf-Td,0); w0=NE(2*pl.pi/T0,4)
PVen=intc((Ven(t))**2,t,Td,Tcf)/(T0)#calculo dos PVIN E PVC PELAS FORMULAS DADAS
PVc=(intc((Vcd(t))**2,t,Td,Tcf)/(T0))
disp("A potencia media do Vin é ",NE(PVen,2))
disp("A potencia media do Vc é ",NE(PVc,2))
#%% Serie fourier para ven
a0_v=2*intc(Ven(t),t,tau0,tau0+T0)/T0# defenir a0_v 
an_v=2*intc(Ven(t)*cos(n*w0*t),t,tau0,tau0+T0)/T0# defenir an_v 
bn_v=2*intc(Ven(t)*sin(n*w0*t),t,tau0,tau0+T0)/T0# defenir bn_v 
Hn_v=an_v*cos(n*w0*t)+bn_v*sin(n*w0*t)# defenir o somatorio da serie de fourrier 
SF_v=simplify(a0_v/2+Symsum(Hn_v,n,1,N))# # defenir serie de fourrier
display(Eq(sym("SFv_n"),SF_v))# mostrar eq
#%% Serie fourier para vc
a0_vc=NE(2*intc(Vcd(t),t,tau0,Tcf)/T0,3)# defenir a0_v 
an_vc=2*intc(Vcd(t)*cos(n*w0*t),t,tau0,tau0+T0)/T0# defenir an_v 
bn_vc=2*intc(Vcd(t)*sin(n*w0*t),t,tau0,tau0+T0)/T0# defenir bn_v
Hn_vc=an_vc*cos(n*w0*t)+bn_vc*sin(n*w0*t)# defenir o somatorio da serie de fourrier
SF_vc=a0_vc/2+Symsum(Hn_vc,n,1,10)# # defenir serie de fourrier
#%% Representaçao grafica de ven
g1=ezplot(Venp(t),[0,T[-1]]);setp(g1,c='b')
xlabel('t');ylabel('Venp')
axis([0,T[-1],min(Vin)-1,max(Vin)+1]);grid('on')
g2=ezplot(subs(SF_v,N,10).doit(),[-0,T[-1]])
setp(g2,c='r')
legend(('$Ven$','$S_10$'))
show()
#%% Reprecentaçao grafica de vc
g3=ezplot(Vcdp(t),[0,T[-1]]);setp(g3,c='b')
xlabel('t');ylabel('Venp')
axis([0,T[-1],min(Vin)-1,max(Vin)+1]);grid('on')
g4=ezplot(SF_vc.doit(),[-0,T[-1]])
setp(g4,c='r')
legend(('$Vc$','$SF_10$'))
show()
#%% E)     obeter o numero do harmonico de erro menor que 11%
Nmax=30# Numero maximo para o ciclo apenas por segurança
Soma=0
par=0
for i in range(1,Nmax):# ciclo para apurar quando é que o erro é menor que 11%
    Pn=double((a0_v/2)**2+(1/2)*sum([subs(an_v,n,k)**2+subs(bn_v,n,k)**2 for k in range(1,i+1)]))    
    erro=100*sqrt(float((PVen-Pn)/PVen))     
    if(erro<11):
        par=i
        print('Erro inferior a 11% em N=',i)
        break
#%% Espectros para ven 
An_v=sqrt(an_v**2+bn_v**2)#modolo de an e bn 
phin_v=atan2(-bn_v,an_v) #angulo entre an e -bn
HnR_v=An_v*cos(n*w0*t+phin_v) # defenir hn_v 
SFR_v=a0_v/2+symsum(HnR_v,n,1,par)# calcular a serie de fourier ate onde o erro é menor que o pedido
W_v=[i*w0 for i in range(11)]#vetor de frequencia angular para poder fazer plot do espetro de amplitude
AN_v=[abs(a0_v/2)]+[subs(An_v,n,i) for i in range(1,11)]#Amplitude ou força dos harmonios 
PHI_v=[subs(phin_v,n,i) for i in range(1,11)]#fase dos harmonios
subplot(1,2,1);
stem(W_v,AN_v);axis([0,3,0,4]);grid(1)
subplot(1,2,2);stem(W_v[1:],PHI_v);axis([0,3,-4,4]);grid(1)
show()
#%% obeter o numero do harmonico de erro menor que 6%
Nmax=30# Numero maximo para o ciclo apenas por segurança
Soma=0
par=0
for i in range(1,Nmax):# ciclo para apurar quando é que o erro é menor que 6%
    Pn=double((a0_vc/2)**2+(1/2)*sum([subs(an_vc,n,k)**2+subs(bn_vc,n,k)**2 for k in range(1,i+1)]))
    erro=100*sqrt(float((abs(PVc-Pn))/PVc))     
    if(erro<6):
        par=i
        print('Erro inferior a 6% em N=',i)
        break
#%%Espectros para vc 
An_vc=sqrt(an_vc**2+bn_vc**2)#modolo de an e bn 
phin_vc=atan2(-bn_vc,an_vc)#angulo entre an e -bn
HnR_vc=An_vc*cos(n*w0*t+phin_vc)# defenir hn_v 
SFRvc=a0_vc/2+symsum(HnR_vc,n,1,par)# calcular a serie de fourier ate onde o erro é menor que o pedido
W_vc=[i*w0 for i in range(11)]#vetor de frequencia angular para poder fazer plot do espetro de amplitude
AN_vc1=[abs(a0_vc/2)]+[subs(An_vc,n,i) for i in range(1,11)]#Amplitude ou força dos harmonios 
PHI_vc=[subs(phin_vc,n,i) for i in range(1,11)]#fase dos harmonios
subplot(1,2,1);
stem(W_vc,AN_vc1);axis([0,3,0,4]);grid(1)
subplot(1,2,2);stem(W_vc[1:],PHI_vc);axis([0,3,-4,4]);grid(1)
show()
#%% Exercicio 2
print("Exercicio 2")
T2=[]#defenir vetores so com valores da segunda descarga
vc2=[]#defenir vetores so com valores da segunda descarga
vin2=[]#defenir vetores so com valores da segunda descarga
Nt=len(T)
per=T[-1]/Nt
nt=t1[2]-t1[0]#numero de amostras da segunda descarga
for i in range(t1[0],t1[2]):
    T2.append(T[i])
for i in range(t1[0],t1[2]):
    vin2.append(Vin[i])
for i in range(t1[0],t1[2]):
    vc2.append(Vc[i])
T2=array(T2)#defenir vetores para segunda descarga
vin2=array(vin2)
vc2=array(vc2)

#%%Serie de fourier numeicamente
an_vc=[]
bn_vc=[]
a0_vc=(2/T0)*(sum(vc2[1:]*per)+sum(vc2[:-1]*per))/2
for i in range(1,11):
    an_vc.append((2/T0)*(sum(vc2[1:]*per*pl.cos(i*w0*T2[1:]))+sum(vc2[:-1]*per*pl.cos(i*w0*T2[:-1])))/2)
    bn_vc.append((2/T0)*(sum(vc2[1:]*per*pl.sin(i*w0*T2[1:]))+sum(vc2[:-1]*per*pl.sin(i*w0*T2[:-1])))/2)
an_vc=array(an_vc)
bn_vc=array(bn_vc)
#%%
SF_vcn=[]
SF_vcn10=0
for i in range(1,11):
    SF_vcn.append(an_vc[i-1]*pl.cos(i*w0*T2)+bn_vc[i-1]*pl.sin(i*w0*T2))
for i in range(0,10):
    SF_vcn10=SF_vcn10+SF_vcn[i]
#%%
SF_vcn10=array(SF_vcn10)
SF_vcn10=a0_vc/2+SF_vcn10
g3=ezplot(Vcdp(t),[0,T[-1]]);setp(g3,c='b')
xlabel('t');ylabel('Venp')
#pl.plot(T2,SF_vcn10,[Td,Tcf])
ezplot(T2,SF_vcn10,[Td,Tcf])
show()
#%%
Nmax=len(an_vc)
Soma=0
par=0
soma1=0   
for i in range(0,Nmax):    
    soma1=an_vc[i]**2+bn_vc[i]**2+soma1         
    Pn=(a0_vc/2)**2+(1/2)*soma1
    erro=100*sqrt(float((abs(PVc-Pn))/PVc))  
    if (erro>100):
        break
    if(erro<7):
        par=i
        print('The aimed N is equal to ',i)
        break
#%%
An_vc=[]
phin_vc=[]
HnR_vc=[]
SFRvc=0
for i in range(0,10):
    An_vc.append(float(sqrt(an_vc[i]**2+bn_vc[i]**2)))
    phin_vc.append(float(atan2(-bn_vc[i],an_vc[i])))
    HnR_vc.append(An_vc[i]*pl.cos((i+1)*w0*T2+phin_vc[i]))
for i in range(0,10):
    SFRvc=SFRvc+HnR_vc[i]
SFRvc=a0_vc/2+SFRvc
W_vc=[i*w0 for i in range(11)]
W_vc=array(W_vc)
AN_vc=[abs(a0_vc/2)]+An_vc
PHI_vc=array(phin_vc)
subplot(1,2,1);
stem(W_vc,AN_vc);axis([0,3,0,4]);grid(1)
subplot(1,2,2);stem(W_vc[1:],PHI_vc);axis([0,3,-4,4]);grid(1)
show()
#%%
#%%
THD=float(sqrt(sum(AN_v)-AN_v[0])/AN_v[0])*100
display(Eq(sym('THD_vin'),THD)) 
#%%
THDc=sqrt(sum(AN_vc1)-AN_vc1[0])/AN_vc1[0]
display(Eq(sym('THD_vc'),THD))