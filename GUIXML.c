#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "xml.c/src/xml.h"

int main()
{
    FILE * stream;
    
    stream = fopen("ejemplo.xml", "r");
    
    struct xml_document* document = xml_open_document(stream);
    
    if (!document)
    {
        printf("Could parse document\n");
        exit(-1);
    }
    else
    {
        printf("\n");
        printf("Fichero leido con éxito.\n");
    }
    struct xml_node* root = xml_document_root(document);
    
    int num_nodos=xml_node_children(root);
    
    printf ("\n");
    printf("Numero de nodos es %i.\n",num_nodos);
    printf ("\n");

    for (int i = 0; i < num_nodos; i++)
    {
        struct xml_node* nodo = xml_node_child(root, i);
        struct xml_string* nombreNodo = xml_node_name(nodo);
        struct xml_string* contenidoNodo = xml_node_content(nodo);
        struct xml_string* atributoNombreNodo = xml_node_attribute_name(nodo, i);
        struct xml_string* atributoContentNodo = xml_node_attribute_content(nodo, i);

        char* nombreNodo_S = calloc(xml_string_length(nombreNodo) + 1, sizeof(char));
        char* contenidoNodo_S = calloc(xml_string_length(contenidoNodo) + 1, sizeof(char));
        char* atributoNombreNodo_S = calloc(xml_string_length(atributoNombreNodo) + 1, sizeof(char));
        char* atributoContentNodo_S = calloc(xml_string_length(atributoContentNodo) + 1, sizeof(char));
    
        xml_string_copy(nombreNodo, nombreNodo_S, xml_string_length(nombreNodo));
        xml_string_copy(contenidoNodo, contenidoNodo_S, xml_string_length(contenidoNodo));
        xml_string_copy(atributoNombreNodo, atributoNombreNodo_S, xml_string_length(atributoNombreNodo));
        xml_string_copy(atributoContentNodo, atributoContentNodo_S, xml_string_length(atributoContentNodo));
    
        printf("Nodo leido N= %s *** C= %s.\n", nombreNodo_S, contenidoNodo_S);
        printf("Atributo del nodo N= %s *** C= %s.\n", &atributoNombreNodo_S, &atributoContentNodo_S);
        printf("\n");

        atributoNombreNodo_S--;

        free(nombreNodo);
        free(contenidoNodo);
        free(atributoNombreNodo);
        free(atributoContentNodo);
    }
}