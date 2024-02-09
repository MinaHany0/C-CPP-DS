#include <iostream>

int main()
{

    int matA[2][3] = {1,2,3,4,5,6};
    int matB[3][2] = {7,8,9,10,11,12};

    int matC[2][2] = {0,0,0,0};
    

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            for(int a = 0; a < 3; a++)
            {
                matC[i][j] += matA[i][a] * matB[a][j];
            }
            std::cout << matC[i][j] << " ";
        }
        std::cout << "\n";
    }

    delete[][] matA;
    return 0;
}