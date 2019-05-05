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
      v-model="leftDrawerOpen"
      :content-class="$q.theme === 'mat' ? 'bg-grey-2' : null"
    >
      <q-list no-border link inset-delimiter>
        <q-list-header>Essential Links</q-list-header>
        <q-item @click.native="livingroom">
          <q-item-side icon="home"/>
          <q-item-main label="Living Room" sublabel="Control lights in living room"/>
        </q-item>
         <q-item @click.native="bedroom">
          <q-item-side icon="hotel"/>
          <q-item-main label="Bedroom" sublabel="Control lights in bedroom"/>
        </q-item>
        <q-item @click.native="kitchen">
          <q-item-side icon="kitchen"/>
          <q-item-main label="Kitchen" sublabel="Control lights in kitchen"/>
        </q-item>
         <q-item @click.native="presets">
          <q-item-side icon="star"/>
          <q-item-main label="Presets" sublabel="Use custom lighting schemes"/>
        </q-item>
        <q-item @click.native="settings">
          <q-item-side icon="settings"/>
          <q-item-main label="Settings" sublabel="Configuration options"/>
        </q-item>
        <!-- <q-item @click.native="openURL('https://discord.gg/5TDhbDg')">
          <q-item-side icon="chat"/>
          <q-item-main label="Discord Chat Channel" sublabel="https://discord.gg/5TDhbDg"/>
        </q-item>
        <q-item @click.native="openURL('http://forum.quasar-framework.org')">
          <q-item-side icon="record_voice_over"/>
          <q-item-main label="Forum" sublabel="forum.quasar-framework.org"/>
        </q-item>
        <q-item @click.native="openURL('https://twitter.com/quasarframework')">
          <q-item-side icon="rss feed"/>
          <q-item-main label="Twitter" sublabel="@quasarframework"/>
        </q-item> -->
      </q-list>
    </q-layout-drawer>

    <q-page-container>
      <router-view/>
    </q-page-container>
  </q-layout>
</template>

<script>
import { openURL } from "quasar";

export default {
  name: "MyLayout",
  data() {
    return {
      leftDrawerOpen: this.$q.platform.is.desktop
    };
  },
  methods: {
    openURL
  }
};
</script>

<style>
</style>
