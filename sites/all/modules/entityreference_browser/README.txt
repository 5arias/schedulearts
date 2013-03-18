CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Installation
 * Usage
 * Views editing


INTRODUCTION
------------

This is an edit widget for Entity Reference fields. Work is also underway to
make this edit widget compatible with the References module. It uses a 
view for selecting items and the view can be paginated and have exposed filters. 
Included is a default view and you are free to clone it and make any changes 
you need. 

INSTALLATION
------------

Install module as you normally would.

Configure your Node fields:
1.) Go to your node field edit page
2.) Select the "Browser" widget type
3.) Select a view, you can choose the default
    "Entity Reference Browser - Default (block_1)" or choose one that you have 
    modified. Note, only views with the 'entityreference_browser' tag will
    appear in this list.
4.) Save your widget settings

Now go and add/edit a node and bask in the glory :)

USAGE
-----

You will see a widget with two main areas, the left will display the selected 
nodes and the right is the browser. Everything is ajax so it is quite fast. 
Just click the title of the node you want to add and it will appear on the left. 
You can quickly add as many as you want. Then on the left you can re-arrange 
them by just drag/dropping them. You can also easily remove one by selecting 
the [remove] link.


VIEWS EDITING
-------------
 
The module has a way of hiding selected items from the View.
Simply add a base field contextual argument (Product ID for products, Node ID 
for nodes, etc) and in the "More" fieldset enable "Allow multiple values" and 
"Exclude". Then edit the Entity Reference field, and in the widget settings 
enable "Pass selected entity ids to View ".
