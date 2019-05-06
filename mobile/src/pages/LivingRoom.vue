<template>
  <div>
    <q-page padding>
      Living Room
      <q-btn @click="pickColor('red')" color="red" class="full-width" label="Ceiling pixels red"/>
      <q-btn @click="pickColor('green')" color="green" text-color="black" class="full-width" label="Ceiling pixels green"/>
      <q-btn @click="pickColor('blue')" color="blue" class="full-width" label="Ceiling pixels blue"/>
      <q-btn @click="pickColor('yellow')" color="yellow" text-color="black" class="full-width" label="Ceiling pixels yellow"/>
      <q-btn @click="pickColor('purple')" color="purple" class="full-width" label="Ceiling pixels purple"/>
      <q-btn @click="pickColor('white')" color="white" text-color="black" class="full-width" label="Ceiling pixels white"/>
      <q-btn @click="pickColor('black')" color="black" class="full-width" label="turn Ceiling pixels off"/>
    </q-page>
  </div>
</template>

<script>
export default {
  name: "LivingRoom",
  methods: {
    pickColor: (color) => {
      console.log("color: " + color);
    }
  }
};
</script>

<style scoped>
  .q-btn {
    margin: 5px;
  }
</style>
