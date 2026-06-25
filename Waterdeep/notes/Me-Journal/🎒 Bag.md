```ui
inventory_data({rows:7, cols:3, items:[], cell_size:70, show_selected:false})
inventory(inventory_data, "", 244, 7, 3)

```

```ui
cp(0)
sp(0)
ep(0)
gp(10)
pp(0)
total_cp(cp + sp * 10 + ep * 50 + gp * 100 + pp * 1000)
int(cp, "[color=#B87333]Punta[/color]", 80, true)  int(sp, "[color=#C0C0C0] Frag   [/color]", 80, true) 
int(ep, "[color=#D4AF37]Taol    [/color]", 80, true)  int(gp, "[color=#FFD700]    Drac    [/color]", 80, true) 
int(pp, "[color=#AEE7FF]                     Sol       [/color]", 80, true) 
text("[color=#66FFCC]Total value[/color]")  text("cp: ") text(total_cp)
```