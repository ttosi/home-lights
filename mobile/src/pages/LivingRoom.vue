<template>
  <div>
    <q-page padding>
      <q-card color="grey-2">
        <q-card-title class="text-black">Solid Colors</q-card-title>
        <q-card-separator/>
        <q-card-main>
          <q-btn
            @click="pickColor('white')"
            color="white"
            text-color="black"
            class="full-width"
            label="white"
          />
          <q-btn @click="pickColor('red')" color="red" class="full-width" label="red"/>
          <q-btn
            @click="pickColor('green')"
            color="green"
            text-color="black"
            class="full-width"
            label="green"
          />
          <q-btn @click="pickColor('blue')" color="blue" class="full-width" label="blue"/>
          <q-btn
            @click="pickColor('yellow')"
            color="yellow"
            text-color="black"
            class="full-width"
            label="yellow"
          />
          <q-btn @click="pickColor('purple')" color="purple" class="full-width" label="purple"/>
          <q-btn @click="pickColor('black')" color="black" class="full-width" label="off"/>
        </q-card-main>
      </q-card>
      <br>
      <q-card color="grey-2">
        <q-card-title class="text-black">Effects</q-card-title>
        <q-card-separator/>
        <q-card-main>
          <q-btn
            @click="pickColor('fade')"
            color="white"
            text-color="black"
            class="full-width"
            label="Fade in/out"
          />
          <q-btn
            @click="pickColor('strobe')"
            color="white"
            text-color="black"
            class="full-width"
            label="strobe"
          />
          <q-btn
            @click="pickColor('kit')"
            color="white"
            text-color="black"
            class="full-width"
            label="kit"
          />
          <q-btn
            @click="pickColor('sparkle')"
            color="white"
            text-color="black"
            class="full-width"
            label="sparkle"
          />
          <q-btn
            @click="pickColor('runninglights')"
            color="white"
            text-color="black"
            class="full-width"
            label="running lights"
          />
          <q-btn
            @click="pickColor('rainbow')"
            color="white"
            text-color="black"
            class="full-width"
            label="rainbow"
          />
          <q-btn
            @click="pickColor('chase')"
            color="white"
            text-color="black"
            class="full-width"
            label="chase"
          />
          <q-btn
            @click="pickColor('meteor')"
            color="white"
            text-color="black"
            class="full-width"
            label="meteor"
          />
        </q-card-main>
      </q-card>
    </q-page>
  </div>
</template>

<script>
import Vue from "vue";

export default {
  name: "LivingRoom",
  methods: {
    pickColor: color => {
      Vue.http
        .get("http://localhost:3000/home/myroom/ceiling/fill/red")
        .then(response => {
          if(response.status !== 200) {
            throw 'could not send request to server';
          }
        });
    }
  }
};
</script>

<style scoped>
.q-btn {
  margin: 5px;
}
</style>
