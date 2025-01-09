#include "graphLib.h"

#include <stdlib.h>

void graphCreate(GraphType *self)
{
    self->num_nodes = 0;
    self->node = NULL;
}

void graphDestroyPartial(NodeType *node)
{
    if (node->num_links > 0)
    {
        for (size_t i = 0; i < node->num_links; ++i)
        {
            graphDestroyPartial(node->links[i].node);
        }
    }
    free(node);
}

void graphDestroy(GraphType *self)
{
    if (self->num_nodes == 0)
    {
        return;
    }
    graphDestroyPartial(self->node);
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

bool graphPartialContains(NodeType *node, unsigned long id)
{
    if (node->id == id)
    {
        return true;
    }
    for (size_t i = 0; i < node->num_links; ++i)
    {
        if (graphPartialContains(node->links[i].node, id))
        {
            return true;
        }
    }
    return false;
}

bool graphContains(const GraphType *self, unsigned long id)
{
    for (size_t i = 0; i < self->num_nodes; ++i)
    {
        if (graphPartialContains(self->node, id))
        {
            return true;
        }
    }
    return false;
}

bool graphPartialAddLink(NodeType *self, unsigned long destId, LinkType *link)
{
    if (self->id == destId)
    {
        self->num_links++;
        self->links = (LinkType *)realloc(self->links, self->num_links * sizeof(LinkType));
        self->links[self->num_links - 1] = *link;
        return true;
    }
    for (size_t i = 0; i < self->num_links; ++i)
    {
        return graphPartialAddLink(self->links[i].node, destId, link);
    }
    return false;
}

bool graphInsert(GraphType *self, unsigned long parentId, unsigned long id, unsigned long distance)
{
    bool res = false;
    if ((self->num_nodes == 0 && parentId != 0) || (self->num_nodes == 1 && self->node->id != parentId))
    {
        return res;
    }
    if (self->num_nodes == 0 && parentId == 0)
    {
        self->node = (NodeType *)malloc(sizeof(NodeType));
        self->node->id = id;
        self->node->num_links = 0;
        self->node->links = NULL;
        self->num_nodes = 1;
        return true;
    }

    LinkType link = {
        .node = (NodeType *)malloc(sizeof(NodeType)),
        .distance = distance};
    link.node->id = id;
    link.node->num_links = 0;
    link.node->links = NULL;

    if (graphPartialAddLink(self->node, parentId, &link))
    {
        self->num_nodes++;
        return true;
    }
    return false;
}

bool graphPartialRemoveLink(NodeType *self, unsigned long destId)
{
    // Check if node links contain destId
    for (size_t i = 0; i < self->num_links; ++i)
    {
        if (self->links[i].node->id == destId)
        {
            // Remove link
            free(self->links[i].node->links);
            free(self->links[i].node);
            for (size_t j = i; j < self->num_links - 1; ++j)
            {
                self->links[j] = self->links[j + 1];
            }
            self->num_links--;
            self->links = (LinkType *)realloc(self->links, self->num_links * sizeof(LinkType));
            return true;
        }
    }
    // Check if children links contain destId
    for (size_t i = 0; i < self->num_links; ++i)
    {
        if (graphPartialRemoveLink(self->links[i].node, destId))
        {
            return true;
        }
    }
    return false;
}

bool graphRemove(GraphType *self, unsigned long id)
{
    return graphPartialRemoveLink(self->node, id);
}
