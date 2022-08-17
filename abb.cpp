#include <iostream>
using namespace std;

class noh {
	private:
		noh *left, *right;
		int chave;
	public:
		noh (int chave) {
			this-> chave = chave;
			left = NULL;
			right = NULL;
		}
		
		int getChave() {
			return chave;
		}
		
		noh* getLeft() {
			return left;
		}
		
		noh* getRight() {
			return right;
		}
		
		void setLeft (noh* no) {
			left = no;
		}
		
		void setRight (noh* no) {
			right = no;
		}
};

class arvore {
	private:
		noh* raiz;
	public:
		arvore() {
			raiz = NULL;
		}
		
		void inserir (int chave) {
			if (raiz == NULL)
				raiz = new noh(chave);
			else 
				inserirNoh(raiz, chave);
		}
		
		void inserirNoh(noh* no, int chave) {
				if(chave < no-> getChave()) {
					if (no->getLeft() == NULL) {
						noh* novoNoh = new noh(chave);
						no->setLeft(novoNoh);
					}
					else {
						inserirNoh(no->getLeft(), chave);
					}
				} else if (chave > no->getChave()){
					if (no->getRight() == NULL) {
						noh* novoNoh = new noh(chave);
						no->setRight(novoNoh);
					}
					else {
						inserirNoh(no->getRight(), chave);
					}
				}
		}
		
		noh* getRaiz() {
			return raiz;
		}
		
		void emOrdem(noh* no){
			if (no != NULL) {
				emOrdem(no->getLeft());
				cout << no->getChave() << " ";
				emOrdem(no->getRight());
			}
		}
};

int main() {
	arvore arv;
	int i, n, m;
	
	cin>> n;
	for (i=0; i<n; i++) {
		cin>>m;
		arv.inserir(m);
	}
	
	arv.emOrdem(arv.getRaiz());
	
	return 0;
}
