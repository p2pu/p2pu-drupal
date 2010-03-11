$Id: README.txt,v 1.3 2009/04/07 18:42:31 darrenoh Exp $

OVERVIEW

Nodes hold content. Views save queries. Wouldn't be great if a node could hold a
saved query? Now it can. Viewfield is a CCK field module that allows
administrators to put views directly into nodes. When creating a node, users can
select from a list of views. When the node is displayed, the view is run and the
content is inserted into the body of the node.



INSTALLATION

This module requires the views.module and content.module. Enable these modules,
then enable viewfield.module. You're ready to go.

TODO

1. Provide better control over each view in multiselect fields.
2. Use exposed views to allow for more point and click control over the view at
node add time.
3. Integrate this module back into views when CCK becomes part of core.

AUTHOR

Mark Fredrickson
mark.m.fredrickson@advantagelabs.com
