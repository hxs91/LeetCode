class Solution {
public:
    map< UndirectedGraphNode *,UndirectedGraphNode * > h;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return NULL;
        if( h.find(node)!=h.end() ) return h[node];
        UndirectedGraphNode * p = new UndirectedGraphNode(node->label);
        h.insert( map< UndirectedGraphNode *,UndirectedGraphNode * >::value_type(node,p) );
        int len = (node->neighbors).size();
        for(int i=0;i<len;i++){
            p->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return p;
    }
};
