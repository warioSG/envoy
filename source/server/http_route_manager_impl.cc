#include "server/http_route_manager_impl.h"

namespace Envoy {
namespace Server {

std::vector<Router::RouteConfigProviderSharedPtr> HttpRouteManagerImpl::routeConfigProviders() {
  std::vector<Router::RouteConfigProviderSharedPtr> ret;
  ret.reserve(route_config_providers_.size());
  for (const auto& element : route_config_providers_ ) {
    ret.push_back(element.second.lock());
  }
  return ret;
};

void HttpRouteManagerImpl::addConfigProvider(const std::string& name,
                       std::weak_ptr<Router::RouteConfigProvider> route_config_provider) {
  route_config_providers_.insert({name, route_config_provider});
};

Router::RouteConfigProviderSharedPtr HttpRouteManagerImpl::getConfigProvider(const std::string& name) {
  auto it = route_config_providers_.find(name);
  if (it == route_config_providers_.end()) {
    return nullptr;
  }
  return it->second.lock();
};

void HttpRouteManagerImpl::removeRouteConfigProvider(const std::string& name) {
  route_config_providers_.erase(name);
};

} // namespace Server
} // namespace Envoy