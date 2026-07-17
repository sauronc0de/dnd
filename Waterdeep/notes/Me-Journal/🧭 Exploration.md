```mermeid
kanban
  a[🔍 To Investigate]
    c1[Undermountain]: Necessitem diners o més poder per anar al undermountain.
  a[📝 Available]
    c2[Somni]: Un somni misterios amb una ciutat i una criatura terrorifica. Possiblament al Undermountain ja que era un lloc tancat.
    c2[Escriptor]: Vol veurens a la taverna
    c3[Tresor de Neverenguer]: Ajudarem al fill Neverenguer a trobar el tresor si existeix. Ens dóna entrades per anar a la Opera amb en Mirth. Clarament el penjoll tenia alguna pista de tot plegat. 
a[⚔ In Progress]
    c1[Necklace]: Fill the necklace with charms related to my 7 lifes   
    c2[Obrir una taverna]: 
  a[✅ Completed]
    c1[Bolo]: Ha perdut un amic pels carrers de la ciutat amb la violencia que hi ha últimament pels carrers de prop del port. 500 Dracs per trobar el seu amic. (50 per avançat)
  a[❌ Failed]
```


```ui
enum(selected_map, "🗺 Select", 220, ["Faerun", "Waterdeep"])

if(starts_with(selected_map, "Faerun")){ map(faerun_map, 500, 500) }
if(starts_with(selected_map, "Waterdeep")){ map(waterdeep_map, 500, 500) }
```