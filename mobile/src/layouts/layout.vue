<template>
  <q-layout view="lHh Lpr lFf">
    <q-layout-header>
      <q-toolbar color="dark">
        <q-btn flat dense round @click="leftDrawerOpen = !leftDrawerOpen" aria-label="Menu">
          <q-icon name="menu"/>
        </q-btn>
        <q-toolbar-title>
          Home Lights
          <div slot="subtitle">Controlling your home lighting</div>
        </q-toolbar-title>
      </q-toolbar>
    </q-layout-header>
    <q-layout-drawer
      v-model="leftDrawerOpen" content-class="$q.theme === 'dark' ? 'bg-grey-2' : null">
      <q-list no-border link inset-delimiter>
        <q-item @click.native="$router.push('/')">
          <q-item-side icon="home"/>
          <q-item-main label="Home"/>
        </q-item>
        <q-item @click.native="$router.push('/livingroom')">
          <q-item-side icon="tv"/>
          <q-item-main label="Living Room" sublabel="Control lights in living room"/>
        </q-item>
        <q-item @click.native="$router.push('/bedroom')">
          <q-item-side icon="hotel"/>
          <q-item-main label="Bedroom" sublabel="Control lights in bedroom"/>
        </q-item>
        <q-item @click.native="$router.push('/kitchen')">
          <q-item-side icon="kitchen"/>
          <q-item-main label="Kitchen" sublabel="Control lights in kitchen"/>
        </q-item>
        <q-item @click.native="$router.push('/presets')">
          <q-item-side icon="star"/>
          <q-item-main label="Presets" sublabel="Use custom lighting schemes"/>
        </q-item>
        <q-item @click.native="$router.push('/settings')">
          <q-item-side icon="settings"/>
          <q-item-main label="Settings" sublabel="Configuration options"/>
        </q-item>
      </q-list>
    </q-layout-drawer>
    <q-page-container>
      <router-view/>
    </q-page-container>
  </q-layout>
</template>

<script>
export default {
  name: "layout",
  data() {
    return {
      leftDrawerOpen: this.$q.platform.is.desktop
    };
  },
  methods: {
    test: () => {
      console.log("yo!");
    }
  }
};
</script>

<style>
</style>
