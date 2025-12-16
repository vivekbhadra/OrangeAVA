set hlsearch
set tabstop=4
" --- ctags and cscope Integration for Code Walkthrough ---

" 1. Configure tags: Search for the 'tags' file in the current directory (./tags)
"    and recursively search up the directory tree (;) until the root.
"    This is essential for large projects when editing files deep in subdirectories.
set tags=./tags;

" 2. Automatically load the cscope database:
"    Check if the CSCOPE_DB environment variable is set (which should point to cscope.out).
"    If it is, add the database to Vim's list of searchable databases.
if $CSCOPE_DB != ""
  cs add $CSCOPE_DB
endif

" 3. Enable unified navigation:
"    Instructs Vim to use the cscope database for standard tag lookup commands (like Ctrl+]).
"    This allows cscope's powerful relation-finding capabilities to augment ctags.
set cscopetag

