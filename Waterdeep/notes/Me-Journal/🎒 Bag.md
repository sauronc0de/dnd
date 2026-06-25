```ui
inventory_data({rows:7, cols:3, items:[{name:"Forgery kit", image:"../Img/Items/forgery-kit.png", color:"#9F9F9F", position:0}, {name:"Custome", image:"../Img/Items/roba-de-peregri.png", color:"#9F9F9F", position:1}, {name:"Caltrops", image:"../Img/Items/caltrops.png", quantity:"10", color:"#9F9F9F", position:2}, {name:"Flask of oil", image:"../Img/Items/flask-of-oil.png", quantity:"2", color:"#9F9F9F", position:3}, {name:"Day of ration", image:"../Img/Items/day-ration.png", quantity:"10", color:"#9F9F9F", position:4}, {name:"Rope", image:"../Img/Items/rope.png", tooltip:"20m of rope", color:"#9F9F9F", position:5}, {name:"Tinderbox", image:"../Img/Items/tinderbox.png", color:"#9F9F9F", position:6}, {name:"Torch", image:"../Img/Items/torch.png", quantity:"10", color:"#9F9F9F", position:7}, {name:"Waterskin", image:"../Img/Items/waterskin.png", color:"#9F9F9F", position:8}], cell_size:70, show_selected:false})
inventory(inventory_data, "", 244, 7, 3)

```

```ui
cp(0)
sp(0)
ep(20)
gp(10)
pp(0)
total_cp(cp + sp * 10 + ep * 50 + gp * 100 + pp * 1000)
int(cp, "[color=#B87333]Punta[/color]", 80, true)  int(sp, "[color=#C0C0C0] Frag   [/color]", 80, true) 
int(ep, "[color=#D4AF37]Taol    [/color]", 80, true)  int(gp, "[color=#FFD700]    Drac    [/color]", 80, true) 
int(pp, "[color=#AEE7FF]                     Sol       [/color]", 80, true) 
text("[color=#66FFCC]Total value[/color]")  text("cp: ") text(total_cp)
```