#include <iostream>

void afficherMatrice(double mat[3][3], int ordre) {
    for (int i = 0; i < ordre; ++i) {
        for (int j = 0; j < ordre; ++j) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void additionner(double mat1[3][3], double mat2[3][3], double res[3][3], int ordre) {
    for (int i = 0; i < ordre; ++i) {
        for (int j = 0; j < ordre; ++j) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
} // g++ matrice.cpp -o matriceprogram

void soustraire(double mat1[3][3], double mat2[3][3], double res[3][3], int ordre) {
    for (int i = 0; i < ordre; ++i) {
        for (int j = 0; j < ordre; ++j) {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplier(double mat1[3][3], double mat2[3][3], double res[3][3], int ordre) {
    for (int i = 0; i < ordre; ++i) {
        for (int j = 0; j < ordre; ++j) {
            res[i][j] = 0;
            for (int k = 0; k < ordre; ++k) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

double determinant2x2(double mat[2][2]) {
    return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
}

double determinant3x3(double mat[3][3]) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
        mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
        mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

double trace(double mat[3][3], int ordre) {
    double t = 0;
    for (int i = 0; i < ordre; ++i) {
        t += mat[i][i];
    }
    return t;
}

bool inverse2x2(double mat[2][2], double res[2][2]) {
    double det = determinant2x2(mat);
    if (det == 0) {
        std::cout << "Matrice non inversible." << std::endl;
        return false;
    }
    double invDet = 1 / det;
    res[0][0] = mat[1][1] * invDet;
    res[0][1] = -mat[0][1] * invDet;
    res[1][0] = -mat[1][0] * invDet;
    res[1][1] = mat[0][0] * invDet;
    return true;
}

bool inverse3x3(double mat[3][3], double res[3][3]) {
    double det = determinant3x3(mat);
    if (det == 0) {
        std::cout << "Matrice non inversible." << std::endl;
        return false;
    }
    double invDet = 1 / det;

    res[0][0] = (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) * invDet;
    res[0][1] = (mat[0][2] * mat[2][1] - mat[0][1] * mat[2][2]) * invDet;
    res[0][2] = (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]) * invDet;

    res[1][0] = (mat[1][2] * mat[2][0] - mat[1][0] * mat[2][2]) * invDet;
    res[1][1] = (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]) * invDet;
    res[1][2] = (mat[0][2] * mat[1][0] - mat[0][0] * mat[1][2]) * invDet;

    res[2][0] = (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]) * invDet;
    res[2][1] = (mat[0][1] * mat[2][0] - mat[0][0] * mat[2][1]) * invDet;
    res[2][2] = (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]) * invDet;

    return true;
}

int main() {
    int ordre;
    std::cout << "Entrez l'ordre de la matrice (2 ou 3): ";
    std::cin >> ordre;

    if (ordre == 2) {
        double mat1[2][2], mat2[2][2];
        double res[2][2];

        std::cout << "Entrez les éléments de la première matrice (2x2): " << std::endl;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                std::cin >> mat1[i][j];

        std::cout << "Entrez les éléments de la deuxième matrice (2x2): " << std::endl;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                std::cin >> mat2[i][j];

        std::cout << "Première matrice: " << std::endl;
        afficherMatrice(mat1, 2);
        std::cout << "Deuxième matrice: " << std::endl;
        afficherMatrice(mat2, 2);

        additionner(mat1, mat2, res, 2);
        std::cout << "Somme des matrices: " << std::endl;
        afficherMatrice(res, 2);

        soustraire(mat1, mat2, res, 2);
        std::cout << "Différence des matrices: " << std::endl;
        afficherMatrice(res, 2);

        multiplier(mat1, mat2, res, 2);
        std::cout << "Produit des matrices: " << std::endl;
        afficherMatrice(res, 2);

        std::cout << "Déterminant de la première matrice: " << determinant2x2(mat1) << std::endl;
        std::cout << "Déterminant de la deuxième matrice: " << determinant2x2(mat2) << std::endl;

        double inv[2][2];
        if (inverse2x2(mat1, inv)) {
            std::cout << "Inverse de la première matrice: " << std::endl;
            afficherMatrice(inv, 2);
        }

        if (inverse2x2(mat2, inv)) {
            std::cout << "Inverse de la deuxième matrice: " << std::endl;
            afficherMatrice(inv, 2);
        }

    }
    else if (ordre == 3) {
        double mat1[3][3], mat2[3][3];
        double res[3][3];

        std::cout << "Entrez les éléments de la première matrice (3x3): " << std::endl;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                std::cin >> mat1[i][j];

        std::cout << "Entrez les éléments de la deuxième matrice (3x3): " << std::endl;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                std::cin >> mat2[i][j];

        std::cout << "Première matrice: " << std::endl;
        afficherMatrice(mat1, 3);
        std::cout << "Deuxième matrice: " << std::endl;
        afficherMatrice(mat2, 3);

        additionner(mat1, mat2, res, 3);
        std::cout << "Somme des matrices: " << std::endl;
        afficherMatrice(res, 3);

        soustraire(mat1, mat2, res, 3);
        std::cout << "Différence des matrices: " << std::endl;
        afficherMatrice(res, 3);

        multiplier(mat1, mat2, res, 3);
        std::cout << "Produit des matrices: " << std::endl;
        afficherMatrice(res, 3);

        std::cout << "Déterminant de la première matrice: " << determinant3x3(mat1) << std::endl;
        std::cout << "Déterminant de la deuxième matrice: " << determinant3x3(mat2) << std::endl;

        double inv[3][3];
        if (inverse3x3(mat1, inv)) {
            std::cout << "Inverse de la première matrice: " << std::endl;
            afficherMatrice(inv, 3);
        }

        if (inverse3x3(mat2, inv)) {
            std::cout << "Inverse de la deuxième matrice: " << std::endl;
            afficherMatrice(inv, 3);
        }

    }
    else {
        std::cout << "Ordre de matrice non valide. Choisissez entre 2 ou 3." << std::endl;
    }

    return 0;
}
