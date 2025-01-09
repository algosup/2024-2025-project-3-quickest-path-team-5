/*!
    \file graphLib.c
    \brief Graph library
    \authors CHARLES Rémy, CARON Maxime
*/

#include "graphLib.h"

#include <stdlib.h>

void graphCreate(GraphType *self)
{
    self->num_nodes = 0;
    self->nodes = NULL;
}

void graphDestroyPartial(NodeType *node)
{
    for (size_t i = 0; i < node->num_links; ++i)
    {
        graphDestroyPartial(node->links[i].node);
    }
    free(node->links);
    free(node);
    return;
}

void graphDestroy(GraphType *self)
{
    for (size_t i = 0; i < self->num_nodes; ++i)
    {
        graphDestroyPartial(self->nodes[i]);
    }
    return;
}

bool graphEmpty(const GraphType *self)
{
    return (self->num_nodes == 0);
}

size_t graphSize(const GraphType *self)
{
    return self->num_nodes;
}

bool graphContains(const GraphType *self, unsigned long id)
{
    for (size_t i = 0; i < self->num_nodes; ++i)
    {
        if (self->nodes[i]->id == id)
        {
            return true;
        }
    }
    return false;
}

bool linkExist(GraphType *self, unsigned long id1, unsigned long id2)
{
    for (size_t i = 0; i < self->num_nodes; ++i)
    {
        if (self->nodes[i]->id == id1)
        {
            for (size_t j = 0; j < self->nodes[i]->num_links; ++j)
            {
                if (self->nodes[i]->links[j].node->id == id2)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool graphCreateNode(GraphType *self, unsigned long id)
{
    // Check if node already exists
    if (graphContains(self, id))
    {
        return false;
    }
    // add node tt slef->nodes
    NodeType *node = (NodeType *)malloc(sizeof(NodeType));
    node->id = id;
    node->num_links = 0;
    node->links = NULL;
    self->num_nodes++;
    self->nodes = (NodeType **)realloc(self->nodes, self->num_nodes * sizeof(NodeType *));
    self->nodes[self->num_nodes - 1] = node;
    return true;
}

bool createLink(GraphType *self, unsigned long parentId, unsigned long id, unsigned long distance)
{
    // check if link already exists
    if (linkExist(self, parentId, id))
    {
        return false;
    }

    NodeType *parent = NULL;
    NodeType *child = NULL;
    // check if parent node exists
    for (size_t i = 0; i < self->num_nodes; ++i)
    {
        if (self->nodes[i]->id == id)
        {
            child = self->nodes[i];
        }
        if (self->nodes[i]->id == parentId)
        {
            parent = self->nodes[i];
        }
    }
    if (!parent || !child)
    {
        return false;
    }

    // add link to parent
    parent->num_links++;
    parent->links = (LinkType *)realloc(parent->links, parent->num_links * sizeof(LinkType));
    parent->links[parent->num_links - 1].node = child;
    parent->links[parent->num_links - 1].distance = distance;
    return true;
}

bool graphRemoveNode(GraphType *self, unsigned long id)
{
    // check if node exists
    if (!graphContains(self, id))
    {
        return false;
    }

    NodeType *node = NULL;
    // find node
    for (size_t i = 0; i < self->num_nodes; ++i)
    {
        if (self->nodes[i]->id == id)
        {
            node = self->nodes[i];
        }
    }

    if (!node)
    {
        return false;
    }

    // remove links
    for (size_t i = 0; i < self->num_nodes; ++i)
    {
        for (size_t j = 0; j < self->nodes[i]->num_links; ++j)
        {
            if (self->nodes[i]->links[j].node->id == id)
            {
                for (size_t k = j; k < self->nodes[i]->num_links - 1; ++k)
                {
                    self->nodes[i]->links[k] = self->nodes[i]->links[k + 1];
                }
                self->nodes[i]->num_links--;
                self->nodes[i]->links = realloc(self->nodes[i]->links, self->nodes[i]->num_links * sizeof(LinkType));
            }
        }
    }

    // remove node
    for (size_t i = 0; i < self->num_nodes; ++i)
    {
        if (self->nodes[i]->id == id)
        {
            for (size_t j = i; j < self->num_nodes - 1; ++j)
            {
                self->nodes[j] = self->nodes[j + 1];
            }
            self->num_nodes--;
            self->nodes = realloc(self->nodes, self->num_nodes * sizeof(NodeType *));
            return true;
        }
    }

    return false;
}

bool removeLink(GraphType *self, unsigned long parentId, unsigned long id)
{
    // check if link exists
    if (!linkExist(self, parentId, id))
    {
        return false;
    }
    NodeType *parent = NULL;
    NodeType *child = NULL;
    // find parent and child
    for (size_t i = 0; i < self->num_nodes; ++i)
    {
        if (self->nodes[i]->id == id)
        {
            child = self->nodes[i];
        }
        if (self->nodes[i]->id == parentId)
        {
            parent = self->nodes[i];
        }
    }
    if (!parent || !child)
    {
        return false;
    }
    // remove link
    for (size_t i = 0; i < parent->num_links; ++i)
    {
        if (parent->links[i].node->id == id)
        {
            for (size_t j = i; j < parent->num_links - 1; ++j)
            {
                parent->links[j] = parent->links[j + 1];
            }
            parent->num_links--;
            parent->links = realloc(parent->links, parent->num_links * sizeof(LinkType));
            return true;
        }
    }
    return false;
}
