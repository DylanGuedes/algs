# 1. Greedy
#### 1.1. Apagar n dígitos de um número, deixando o maior número possível
1. Guarde o número como uma string, tome mys como uma stack de chars
2. Itere nesta string. Receba idx, o elemento de cada iteração. Se mys estiver vazio, coloque idx em mys.
3. Se mys não estiver vazio e for possível apagar algum número, veja o topo de mys. Se o topo for maior que o atual, decremente n, e não coloque idx na pilha. Se o topo for menor que o atual, coloque idx na pilha. Se mys não estiver vazio e não for possível apagar algum número, só coloque idx na pilha.

Código (obs: d é n) :
```c++
 vector<char> mys;

 for (auto it : num) {
     if (mys.empty()) {
         mys.push_back(it);
         continue;
     } else {

         while (d && (mys.back() < it) && not mys.empty()) {
             mys.pop_back();
             d--;
         }
         mys.push_back(it);
     }
 }

while (d && not mys.empty()) {
    mys.pop_back();
    d--;
}
```
