#include <iostream>

void indent(int level) {
    // indent more at each level:
    for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst {
    friend void print_bst(const Bst<T>& bst, int level=0) {
        indent(level);
        level++;

        std::cout << "data: " << bst.data << std::endl;
        indent(level + 1);
        std::cout << "left: ";
   
        if (!bst.left) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.left, level);
        }
        indent(level + 1);
        std::cout << "right: ";
        if (!bst.right) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.right, level);
        }
        std::cout << std::endl;
    }

    public:
        Bst(T d, Bst* p=nullptr, Bst* l=nullptr, Bst* r=nullptr)
            : data(d), parent(p), left(l), right(r) {}

        Bst<T>* insert(const T d) {
			if (d == data) return nullptr;
			else if (d < data) {
				if (!left) { //if left == nullptr
					left = new Bst(d, this);
					return left;
				}
				else {
					return left->insert(d);
				}
			}
			else { //d > data
				if (!right) {
					right = new Bst(d, this);
					return right;
				}
				else {
					return right->insert(d);
				}
			}
        }
		T min() {
			if (!left) {
				return data;
			}
			else {
				return left->min();
			}
		}
		T max() {
			if (!right) {
				return data;
			}
			else {
				return right->max();
			}
		}
		Bst<T>* search(const T d) {
			if (d == data) {
				return this;
			}
			else if (data > d) {
				if (!left) {
					return nullptr;
				}
				else {
					return left->search(d);
				}
			}
			else {
				if (!right) {
					return nullptr;
				}
				else {
					return right->search(d);
				}
			}
		}
		Bst<T>* predecessor(const T d) {
			Bst<T>* root = search(d);
			if (!(root->left)) { 
				Bst<T>* node = root->parent;
				while (node != nullptr) {
					if (node->data < root->data) {
						return node;
					}
					else {
						node = node->parent;
					}
				}
			}
			else {
				return search(root->left->max());
			}
		}
		Bst<T>* successor(const T d) {
			Bst<T>* root = search(d);
			if (!(root->right)) {
				Bst<T>* node = root->parent;
				while (node != nullptr) {
					if (node->data > root->data) {
					}
					else {
						node = node->parent;
					}
				}

			}
			else {
				return search(root->right->min());
			}
		}

        T get_val() const {
            return data;
        }

    private:
        T data;
        Bst* parent;
        Bst* left;
        Bst* right;
};


//template <typename T>
//void print_bst(const Bst<T>& bst) {
//void print_bst(Bst<int> bst) {
//    std::cout << "data: " << bst.data << "; left: ";
//
//    if (!bst.left) std::cout << "nullptr ";
//    else {
//        std::cout << "\t\n";
//        print_bst(*bst.left);
//    }
//    std::cout << "; right: ";
//    if (!bst.right) std::cout << "nullptr ";
//    else {
//        std::cout << "\t\n";
//        print_bst(*bst.right);
//    }
//    std::cout << std::endl;
//}
