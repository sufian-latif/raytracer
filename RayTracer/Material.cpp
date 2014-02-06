//
//  Material.cpp
//  RayTracing
//
//  Created by Sufian Latif on 1/24/14.
//
//

# include "Material.h"

map <string, Material> materials;

void loadMaterials(char *file)
{
    FILE* fp = fopen(file, "r");
    char name[100];
    Material mat;
    
    while(fscanf(fp, "%s", name) == 1)
    {
        fscanf(fp, "%lf %lf %lf", &mat.ambient.r, &mat.ambient.g, &mat.ambient.b);
        fscanf(fp, "%lf %lf %lf", &mat.diffuse.r, &mat.diffuse.g, &mat.diffuse.b);
        fscanf(fp, "%lf %lf %lf", &mat.specular.r, &mat.specular.g, &mat.specular.b);
        fscanf(fp, "%lf", &mat.shininess);
        
        materials[string(name)] = mat;
        printf("%s\n", name);
    }
    fclose(fp);
}