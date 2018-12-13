#include <stdio.h>
#include <stdlib.h>
#include "svm.h"

struct svm_parameter param;
struct svm_problem prob;
struct svm_model *model;
struct svm_node *x_space;


void init_param(struct svm_parameter param)
{
    param.svm_type = C_SVC;
    param.kernel_type = LINEAR;
    param.degree = 3;
    param.gamma = 0;
    param.coef0 = 0;
    param.nu = 0.5;

    param.cache_size = 1;
    param.C = 1;
    param.eps = 1e-3;
    param.p = 0.1;
    param.shrinking = 1;
    param.probability = 0;

    param.nr_weight = 0;
    param.weight_label = 0;
    param.weight = 0;
}

void init_data()
{
    struct svm_node** nodes = malloc(sizeof(struct svm_node*) * 2);
    x_space = malloc(sizeof(struct svm_node) * 3);
    x_space[0].index = 1;
    x_space[0].value = 3;
    x_space[1].index = 2;
    x_space[1].value = 3;
    x_space[2].index = -1;
    nodes[0] = x_space;

    x_space = malloc(sizeof(struct svm_node)* 3);
    x_space[0].index = 1;
    x_space[0].value = -1;
    x_space[1].index = 2;
    x_space[1].value = -1;
    x_space[1].index = -1;
    nodes[1] = x_space;

    double *y = malloc(sizeof(double)*2);
    y[0] = -1;
    y[1] = 1;

    prob.l = 2;
    prob.x = nodes;
    prob.y = y;

}

void analyze_data()
{
    model = svm_train(&prob, &param);
}
int main()
{
    init_param(param);
    init_data();
    analyze_data();
    printf("Hello world!\n");
    return 0;
}
