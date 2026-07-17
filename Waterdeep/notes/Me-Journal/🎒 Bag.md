```ui
inventory_data({items:[{name:"Forgery kit", image:"../Img/Items/forgery-kit.png", tooltip:"# Forgery Kit\n\n*Tool (Artisan's Tools)*\n\n**Category:** Items\n\n**Rarity:** None\n\n**Weight:** 5 lb.\n\n## Description\n\nThis small box contains a variety of papers and parchments, pens and inks, seals and sealing wax, gold and silver leaf, and other supplies necessary to create convincing forgeries of physical documents.\n\nProficiency with this kit lets you add your proficiency bonus to any Ability Checks you make to create a physical forgery of a document.", color:"#9F9F9F", x:0, y:0}, {name:"Custome", image:"../Img/Items/roba-de-peregri.png", color:"#9F9F9F", x:1, y:0}, {name:"Caltrops", image:"../Img/Items/caltrops.png", quantity:"10", color:"#9F9F9F", x:2, y:0}, {name:"Flask of oil", image:"../Img/Items/flask-of-oil.png", quantity:"2", color:"#9F9F9F", x:0, y:3}, {name:"Day of ration", image:"../Img/Items/day-ration.png", quantity:"10", color:"#9F9F9F", x:0, y:1}, {name:"Rope", image:"../Img/Items/rope.png", tooltip:"20m of rope", color:"#9F9F9F", x:1, y:1}, {name:"Tinderbox", image:"../Img/Items/tinderbox.png", color:"#9F9F9F", x:2, y:1}, {name:"Torch", image:"../Img/Items/torch.png", quantity:"10", color:"#9F9F9F", x:0, y:2}, {name:"Waterskin", image:"../Img/Items/waterskin.png", color:"#9F9F9F", x:1, y:2}, {name:"Pintues de ciutats", tooltip:"Neverwinter i 3 més", x:2, y:2}, {name:"Bedroll", x:1, y:3}, {name:"Llibre d'encanteris Grumshak", x:2, y:3}]})
inventory(inventory_data, "", 244, 7, 3, 70, 320, 0, "")

```

```ui
cp(0)
sp(9)
ep(0)
gp(26)
pp(0)
total_cp(cp + sp * 10 + ep * 50 + gp * 100 + pp * 1000)
int(cp, "[color=#B87333]Punta[/color]", 80, true)  int(sp, "[color=#C0C0C0] Frag   [/color]", 80, true) 
int(ep, "[color=#D4AF37]Taol    [/color]", 80, true)  int(gp, "[color=#FFD700]    Drac    [/color]", 80, true) 
int(pp, "[color=#AEE7FF]                     Sol       [/color]", 80, true) 
text("[color=#66FFCC]Total value[/color]")  text("cp: ") text(total_cp)
```