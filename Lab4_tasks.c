#include <stdio.h>
#include <math.h> // для функції sqrt

int main() {
    int choice;

    while (1) { // Нескінченний цикл – програма працює, поки не вибрано "вийти"

        // шось типу менюшки
        printf("\n--Меню--\n");
        printf("1. Завдання 1 \n");
        printf("2. Завдання 2 \n");
        printf("3. Завдання 3 \n");
        printf("4. Завдання 4 \n");
        printf("0. Вийти\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice); // Зчитування вибору користувача

        if (choice == 1) {
            int a, b; //цілі числа, введені користувачем.
            double x;  //результат обчислення формули.

            printf("\nЗавдання 1: Обчислити значення функції x = sqrt(a - b*b) + sqrt(a * b)\n"); //обчислення коренем

            while (1) {
                printf("Введіть цілі значення a та b: ");
                scanf("%d %d", &a, &b);

                // Перевірка, чи вирази під коренем не від'ємні
                if ((a - b*b) < 0) {          //перевіряє, чи добуток менше нуля (від’ємний)
                    printf("Помилка: вираз 'a - b*b' є від’ємним.\n");
                    continue; // наступна інтерація циклу :)
                }
                if ((a*b) < 0) {              //ця перевірка робить те самє 
                    printf("Помилка: вираз 'a*b' є від’ємним.\n");
                    continue; 
                }

                // Обчислення виразу
                x = sqrt(a - b*b) + sqrt(a*b);
                printf("Результат: x = %.4f\n", x);
                break; // вихід з циклу 
            }
        }
        else if (choice == 2) {
            int sum = 0, i;
            int loop_choice;
            
            printf("\nЗавдання 2: Обчислити суму чисел, кратних 3 у [10;100)\n");
            printf("Оберіть тип циклу:\n");
            printf("1. з параметром (for)\n");
            printf("2. з передумовою (while)\n");
            printf("3. з післяумовою (do-while)\n");
            printf("Ваш вибір: ");
            scanf("%d", &loop_choice);
            
            if (loop_choice == 1) {
                printf("З використанням циклу for:\n");
                
                for (i = 10; i < 100; i++) {
                    if (i % 3 == 0) {  //перевірка, чи i ділиться на 3 без остачі тоді додаємо інакше пропускаємо.
                        sum += i;
                    }                  //програма обчислює суму всіх чисел від 10 до 100, які діляться на 3
                }
            }
            else if (loop_choice == 2) {
                printf("З використанням циклу while:\n");
                
                i = 10;
                while (i < 100) {
                    if (i % 3 == 0) {
                        sum += i;
                    }
                    i++; 
                }
            }
            else if (loop_choice == 3) {
                printf("З використанням циклу do-while:\n");
               
                i = 10;
                do {
                    if (i % 3 == 0) {
                        sum += i;
                    }
                    i++;                                //Після кожної ітерації значення i збільшується на 1
                } while (i < 100);
            }
            else {
                printf("Нема такого -_- вибери від 1 до 3\n");
                continue; // повернутися в меню
            }
            printf("Сума чисел, кратних 3 у [10;100): %d\n", sum);
        }
        else if (choice == 3) {
            int n, i, j;
            double x, sum = 0, product;
            printf("\nЗавдання 3: Обчислити S = сума добутків (j + x), де j змінюється від 1 до i, а i — від 1 до n\n");
            printf("Введіть натуральне число n: ");
            scanf("%d", &n);
            printf("Введіть дійсне число x: ");
            scanf("%lf", &x);
           // цикл for
            for (i = 1; i <= n; i++) {              
            product = 1;
                for (j = 1; j <= i; j++) {  // <= менше або дорівнює
                    product *= (j + x);     // *= Присвоєння з множенням
                }
                sum += product;
            }

            printf("Результат s = %.2f\n", sum);       
        }
        else if (choice == 4) { // Завдання 4: Табуляція функції y = 1 / (1 - sqrt(x))
            
            printf("\nЗавдання 4: Табуляція функції y = 1 / (1 - sqrt(x))\n");
            printf("Інтервал x: [0, 6] з кроком 0.5\n");

    double a = 0.0; // початок інтервалу (0.0)
    double b = 6.0; // кінець інтервалу (6.0)
    double dx = 0.5; // крок, на який ми змінюємо x після кожної ітерації (0.5)
    double x, y; // змінні  для обчислення 

    printf("*************************\n");
    printf("x\t\ty = f(x)\n");                     //Таблиця як на Прикладі №8
    printf("*************************\n");

    x = a;
    while (x <= b) {
        if (x < 0) {                               
            printf("%.1f\t\tНевизначено (під коренем від'ємне число)\n", x);
        } else if (x == 1) {
            printf("%.1f\t\tНевизначено (ділення на нуль)\n", x);
        } else {
            y = 1.0 / (1.0 - sqrt(x));
            printf("%.1f\t\t%.6f\n", x, y);
        }
        x += dx;
    }
    printf("*************************\n");
        }
        else if (choice == 0) {
            printf("Вихід з програми.\n");
            break; // вихід з головного циклу
        }
        else {
            printf("Неправильний вибір. Спробуйте ще раз.\n");
        }
    }

    return 0;
}
