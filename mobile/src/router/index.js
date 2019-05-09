import Vue from 'vue'
import VueRouter from 'vue-router'
import VueResource from 'vue-resource';

import routes from './routes'

Vue.use(VueRouter)
Vue.use(VueResource)

Vue.prototype.$apiUrl = 'http://localhost:8080/api'

export default function (/* { store, ssrContext } */) {
  const Router = new VueRouter({
    scrollBehavior: () => ({ y: 0 }),
    routes,
    mode: process.env.VUE_ROUTER_MODE,
    base: process.env.VUE_ROUTER_BASE
  })

  return Router
}
