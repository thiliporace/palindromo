#include <ios>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

const int STACK_CAPACITY = 100;

struct Stack {
  int count = 0;
  char elements[STACK_CAPACITY];
};

Stack Create() {
  Stack stack;
  stack.count = 0;
  for (int i = 0; i < STACK_CAPACITY; i++) {
    stack.elements[i] = '\0';
  }
  return stack;
}

bool push(Stack &stack, char e) {
  if (stack.count == STACK_CAPACITY) {
    return false;
  } else {
    stack.elements[stack.count] = e;
    stack.count++;
    return true;
  }
}

bool pop(Stack &stack) {
  if (stack.count == 0) {
    return false;
  }
  char value = stack.elements[stack.count - 1];
  stack.elements[stack.count - 1] = '\0';
  stack.count--;
  return value;
}

char top(Stack &stack) {
  if (stack.count == 0) {
    return '\0';
  }
  return stack.elements[stack.count - 1];
}

void print_top(Stack &stack) {
  char topo = top(stack);
  if (topo == '\0')
    cout << "Pilha vazia. \n";
  else
    cout << "Topo da pilha: " << topo << '\n';
}

int count_stack(Stack &stack) { return stack.count; }

void print_count(Stack &stack) {
  int count = count_stack(stack);
  cout << "Quantidade de elementos na pilha: " << count << "\n";
}

bool is_empty(Stack &stack) { return stack.count == 0; }

int main() {
  Stack pilha = create();
  string frase;
  cout << "Digite uma frase qualquer: ";
  getline(cin, frase);
  for (int i = 0; i < frase.length(); i++) {
    if (frase[i] == ' ') {
      false; // Comando para apenas nao fazer nada(nao consegui pensar em outra
             // maneira de fazer isso)
    } else {
      push(pilha, frase[i]);
    }
  }
  print_count(pilha);
  for (int i = 0; i <= frase.length(); i++) {
    if (frase[i] == ' ') {
      false;
    } else {
      if (top(pilha) == frase[i]) {
        pop(pilha);
      } else {
        cout << "A frase colocada nao e um palindromo.\n";
        break;
      }
    }
  }
  if (top(pilha) == '\0') {
    cout << "A frase e um palindromo.\n";
  }
  return 0;
}
