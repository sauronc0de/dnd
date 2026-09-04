```mermaid
kanban
  a[🔍 To Investigate]
    c4[Find anchor team]: Hauria de trobar alguna cosa que ens uneixi a tots.
      Fer alguna cosa perquè tots vagin més o menys a una.
      Feia molt que no podia està tant temps amb unes mateixes persones sense haver de fugir.
      Haig de lluitar per la unitat.

  a[📝 Available]
    c2[Somni]: Un somni misterios amb una ciutat i una criatura terrorifica.
      Possiblament al Undermountain ja que era un lloc tancat.
      Li explico lo del somni a Xoblob i quan ho sent no ho vol ni sentir. Em fa mig fora de la botiga.

    a1[Tresor de Neverenguer]: Ajudarem al fill Neverenguer a trobar el tresor si existeix.
      Ens dóna entrades per anar a la Opera amb en Mirth.
      Clarament el penjoll tenia alguna pista de tot plegat.

    a3[Acabar amb el "nous" Zhentarim]: Daril
      No ens demana res però deixa clar que no s'hi porta bé.

    a5[Obrir una taverna]
    a6[Carrer maritim (Blau)]: Dieun que hi ha alguna cosa màgica estranya i blava al carrer marítim, al nort de la ciutat.
      La zona alta.

    a7[Hermia al turó de Waterdeep (Halam)]: Anant en compte amb les paraules i demanar-li sobre la amenaça que està patint la ciutat.
    a8[Daril contactarà amb nosaltres]: Es per quedar amb un dels seus que té una info.
  a[⚔ In Progress]
    c1[Necklace]: Fill the necklace with charms related to my 7 lifes
    a1[Undermountain]: Necessitem diners o més poder per anar al undermountain.
      Xoblob diu que busqui mercenaris, aventurers o Xanathar per treure artefactes i info de la zona.
      Però sobretot que no baixi

    a2[Protegir el Gremi d'escrombriaires.]: El gremi dels escombriaries tenen problemes quan intenten fer la seva feina amb lo moguda que està la ciutat.
      Diu que necessita que els escoltem. Que els protegim.
      Recompensa 4 d'or

    a3[Espanta Ocells que ataquen granges]: La Enclave Esmeralda ens damana ajuda per acabar amb aquest atac maligne de les granges
  a[✅ Completed]
    c1[Bolo]: Ha perdut un amic pels carrers de la ciutat amb la violencia que hi ha últimament pels carrers de prop del port.
      500 Dracs per trobar el seu amic. (50 per avançat)
      Al final en dóna una mansió en comptes de l'or.

    a1[Escriptor]: Vol veurens a la taverna.
      Treballa pels nobles i ens dóna feines.

    a2[Salvar llibreria]: Mhir ens demana que salvem una anciana que té una llibreria i l'ha atac un monstre.
      Salvem el seu gat i ens dóna:
      pergamins x4
      miniventilador

    a3[Recistes d'elf]: Estan matant elfs per la ciutat. Vol que acabem amb això.
      25 d'or.
      A més a més sabem que els troben decapitats.
      Han matat sobretot al port a mariners i acostumen anar a la taverna Blumermaid.
      És una taverna que porten elfs així que molts van allà.
      El que saben és que les 3 victimes anaven allà.
      Hem matat el Drow que matava a elf.
      En Gaudenci està molt espentat així que no direm res de qui era
      Daril ens paga generosament i diu que està molt content amb nosaltres. Gaudenci diu que no podem di kies

  a[❌ Failed]
```


```ui
enum(selected_map, "🗺 Select", 220, ["Faerun", "Waterdeep"])

if(starts_with(selected_map, "Faerun")){ map(faerun_map, 500, 500) }
if(starts_with(selected_map, "Waterdeep")){ map(waterdeep_map, 500, 500) }
```