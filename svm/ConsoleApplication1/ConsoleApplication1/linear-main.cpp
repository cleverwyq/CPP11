#include "stdafx.h"
#include "linear.h"
#include "stdio.h"
#include <stdlib.h>

struct parameter param;
struct problem prob;
struct model* models;
struct feature_node* x_space;
struct feature_node* predict_nodes;

#define Malloc(type, size) (type*)(malloc(sizeof(type) * size))

void init_param()
{
	param.C = 1;
	param.eps = 1.0e-4;
}

void init_data()
{
	struct feature_node** nodes = Malloc(struct feature_node*, 4);
	x_space = (feature_node*)malloc(sizeof(struct feature_node) * 3);
	x_space[0].index = 1;
	x_space[0].value = 3;
	x_space[1].index = 2;
	x_space[1].value = 3;
	x_space[2].index = -1;
	nodes[0] = x_space;

	x_space = (feature_node*)malloc(sizeof(struct feature_node) * 3);
	x_space[0].index = 1;
	x_space[0].value = -1;
	x_space[1].index = 2;
	x_space[1].value = -1;
	x_space[2].index = -1;
	nodes[1] = x_space;

	x_space = (feature_node*)malloc(sizeof(struct feature_node) * 3);
	x_space[0].index = 1;
	x_space[0].value = -5;
	x_space[1].index = 2;
	x_space[1].value = -5;
	x_space[2].index = -1;
	nodes[2] = x_space;

	x_space = (feature_node*)malloc(sizeof(struct feature_node) * 3);
	x_space[0].index = 1;
	x_space[0].value = 0;
	x_space[1].index = 2;
	x_space[1].value = 0;
	x_space[2].index = -1;
	nodes[3] = x_space;

	double *y = (double*)malloc(sizeof(double) * 3);
	y[0] = 3;
	y[1] = -1;
	y[2] = -5;
	y[3] = -1;

	prob.l = 4;
	prob.n = 2;
	prob.x = nodes;
	prob.y = y;
	prob.bias = -1;
}

void analyze_data()
{
	models = train(&prob, &param);
	printf("Train done\n");

	predict_nodes = Malloc(feature_node, 3);
	predict_nodes[0].index = 1;
	predict_nodes[0].value = -6;
	predict_nodes[1].index = 2;
	predict_nodes[1].value = -6;
	predict_nodes[2].index = -1;

	double result = predict(models, predict_nodes);
	printf("result : %f\n", result);
}
void main()
{
	init_param();
	init_data();
	analyze_data();
}