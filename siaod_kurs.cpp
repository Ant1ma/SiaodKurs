#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream> 

using namespace std;


class mtrx
{
    private:
        int size_a = 0, size_b = 0;
        int matrixx[50][50];

    public:
        void input(int x)
        {
            ifstream fin;
            fin.open("input.txt");

            //fin.ignore(x);
            string s;

            if (x > 0){
                for (int i = 0; i < x; i++){
                    getline(fin, s);
                }
            }

            fin >> size_a;
            fin >> size_b;
            printf("Matrix_size:\t%d %d\n", size_a, size_b);
            
            

            for (int i = 0; i < size_a; i++){
                for (int j = 0; j < size_b; j++){
                    matrixx[i][j] = 0;
                    fin >> matrixx[i][j];
                }
            }

            for (int i = 0; i < size_a; i++){
                for (int j = 0; j < size_b; j ++){
                    printf("%d\t", matrixx[i][j]);
                }
                printf("\n");
            }
            
            fin.close();
            printf("\n\n");
        }

        int sza(){return size_a;}
        int szb(){return size_b;}
        int mx_c(int a, int b){return matrixx[a][b];}


        void print()
        {
            printf("Matrix:\n");
            printf("%d %d\n", size_a, size_b);
            for (int i = 0; i < size_a; i ++){
                for (int j = 0; j < size_b; j ++){
                    printf("%d ", matrixx[i][j]);
                }
                printf("\n");
            }
        }

        void e_mc(int a, int b, int i, int j, int x)
        {
            size_a = a;
            size_b = b;
            matrixx[i][j] = x;
        }


        void output()
        {
            ofstream fout("output.txt");
            fout << "Result\n";
            fout << size_a << " " << size_b << "\n";
            for (int i = 0; i < size_a; i ++){
                for (int j = 0; j < size_b; j ++){
                    fout << matrixx[i][j] << " ";
                }
                fout << "\n";
            }
            fout.close();
            printf("\n");
        }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    mtrx matrix1;
    mtrx matrix2;
    mtrx res_matrix;
    int fun;
    int a1 = 0, b1 = 0, x = 0;
    matrix1.input(x);
    a1 = matrix1.sza();
    b1 = matrix1.szb();
    int mx1[a1][b1];

    for (int i = 0; i < a1; i++){
        for (int j = 0; j < b1; j++){
            mx1[i][j] = matrix1.mx_c(i, j);
        }
    }

    x = a1 + 1;
    printf("%d\n",x);

    matrix2.input(x);
    int a2 = 0, b2 = 0;
    a2 = matrix2.sza();
    b2 = matrix2.szb();
    int mx2[a2][b2];
    printf("a2 = %d, b2 = %d\n", a2, b2);

    for (int i = 0; i < a2; i++){
        for (int j = 0; j < b2; j++){
            mx2[i][j] = matrix2.mx_c(i, j);
        }
    }

    printf("Enter usable function:\t");
    printf("0 - minus\n1 - plus\n2 - multiplication on count\n3 - multiplication on vector\n4 - multiplication on matrix\n5 - assignment 1-st matrix for 2-nd\n");
    scanf("%d", &fun);
    printf("fun:\t%d\n", fun);

    switch(fun)
    {
        default:
            printf("Not this function");
            break;

        case 0:
            {
                int mx_n[a1][b1];
                for(int i = 0; i < a1; i++){
                    for (int j = 0; j < b1; j ++){
                        mx_n[i][j] = mx1[i][j] - mx2[i][j];
                    }
                }

                for (int i = 0; i < a1; i ++){
                    for(int j = 0; j < b1; j ++){
                        res_matrix.e_mc(a1, b1, i, j, mx_n[i][j]);
                    }
                }            
                break;
            }

        case 1:
            {
                int mx_n[a1][b1];
                for(int i = 0; i < a1; i++){
                    for(int j = 0; j < b1; j ++){
                        mx_n[i][j] = mx1[i][j] + mx2[i][j];
                    }
                }
                
                for (int i = 0; i < a1; i ++){
                    for(int j = 0; j < b1; j ++){
                        res_matrix.e_mc(a1, b1, i, j, mx_n[i][j]);
                    }
                }
                break;
            }
        
        case 2:
            {
                int mx_n[a1][b1];
                int count;
                printf("Enter the number for multiply:\t");
                scanf("%d", &count);
                for(int i = 0; i < a1; i++){
                    for(int j = 0; j < b1; j++){
                        mx_n[i][j] = mx1[i][j] * count;
                    }
                }

                for (int i = 0; i < a1; i ++){
                    for(int j = 0; j < b1; j ++){
                        res_matrix.e_mc(a1, b1, i, j, mx_n[i][j]);
                    }
                }

                break;
            }

        case 3:
            {
                int mx_n[a1];
                int vec[a1];
                printf("Enter the vector for multiply:\t");
                for (int i = 0; i < b1; i++){
                    scanf("%d", &vec[i]);
                }

                for(int i = 0; i < a1; i++){
                    mx_n[i] = 0;
                    for(int j = 0; j < b1; j++){
                        
                        mx_n[i] += mx1[i][j] * vec[j];
                    }
                }

                int x = 1;
                for (int i = 0; i < a1; i ++){
                    res_matrix.e_mc(a1, x, i, x, mx_n[i]);
                }

                break;
            }
        
        case 4:
            {
                int mx_n[a1][b2];
                for (int a = 0; a < a1; a++){
                    for (int b = 0; b < b2; b++){
                        mx_n[a][b] = 0;
                        for (int c = 0; c < b1; c++){
                            mx_n[a][b] += mx1[a][c] * mx2[c][b];
                        }
                    }
                }

                for (int i = 0; i < a1; i ++){
                    for(int j = 0; j < b2; j ++){
                        res_matrix.e_mc(a1, b2, i, j, mx_n[i][j]);
                    }
                }

                break;
            }
        case 5:
            {
                ofstream fout("output.txt");
                string s;
                for (int i = 0; i < 2; i ++){
                    fout << a1 << " " << b1 << "\n";
                    for (int j = 0; j < a1; j ++){
                        for(int k = 0; k < b1; k ++){
                            fout << mx1[j][k] << " ";
                        }
                        fout << "\n";
                    }
                    fout << "\n";
                }
                fout.close();
                break;
            }

        

    }
    res_matrix.print();
    res_matrix.output();
    system("pause");
    return 0;
    
/*/
    puts("Matrix 1\n");
    for (int i = 0; i < a1; i++){
            for (int j = 0; j < b1; j++){
               printf("%d\t", mx1[i][j]);
            }
            puts("\n");
       }

    puts("Matrix 2\n");
    for (int i = 0; i < a2; i++){
        for (int j = 0; j < b2; j++){
            printf("%d\t", mx2[i][j]);
        }
        puts("\n");
    }
/*/
}
